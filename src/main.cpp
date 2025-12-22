#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include <dpp/dpp.h>

int main(int argc, char **argv) {
    const char* env_p = nullptr;
    if (env_p = std::getenv("BOT_TOKEN")) {
        std::cout << "Your BOT_TOKEN is: " << env_p << '\n';
    } else {
        std::cout << "Man, where is the BOT_TOKEN in the env?" << '\n';
        return 1;
    }

    std::filesystem::path p;
    if (argv[1]) {
        p = argv[1];
        if (std::filesystem::is_regular_file(p)) {
            std::cout << "It is regular!" << '\n';
            std::cout << p << '\n';
        }
    } else {
        std::cout << '\n';
        std::cin >> p;
        std::cin.tie();
        std::cout << p << '\n';
    }

    dpp::cluster bot(env_p);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "ping") {
            event.reply("Pong!");
        } else if (event.command.get_command_name() == "join") {
            dpp::guild* g = dpp::find_guild(event.command.guild_id);
            if (!g->connect_member_voice(*event.owner, event.command.get_issuing_user().id)) {
                event.reply("You don't seem to be in a voice channel!");
                return;
            }
            event.reply("Joined your channel!");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
            bot.global_command_create(dpp::slashcommand("join", "Joins your voice channel.", bot.me.id));
        }
    });

    bot.start(dpp::st_wait);
    return 0;
}
