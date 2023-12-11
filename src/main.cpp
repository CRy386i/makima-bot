#include <dpp/dpp.h>
#include <iomanip>
#include <sstream>

const std::string BOT_TOKEN = "";

int main() {
	dpp::cluster bot(BOT_TOKEN);

	bot.on_log(dpp::utility::cout_logger());

	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "ping") {
					event.reply("Pong!");
			}
		});

	bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
			if (event.command.get_command_name() == "join") {
					dpp::guild* g = dpp::find_guild(event.command.guild_id);
					auto current_vc = event.from->get_voice(event.command.guild_id);
					bool join_vc = true;

					if (current_vc) {
							auto users_vc = g->voice_members.find(event.command.get_issuing_user().id);

							if (users_vc != g->voice_members.end() && current_vc->channel_id == users_vc->second.channel_id) {
									join_vc = false;

									// quckly puk.
									// current_vc->send_audio_raw();

							} else {
									event.from->disconnect_voice(event.command.guild_id);
									join_vc = true;
							}
					}

					if (join_vc) {
							if (!g->connect_member_voice(event.command.get_issuing_user().id)) {
									event.reply("You don't seem to be in a voice channel!");
									return;
							}
							//event.voice_client->send_audio_raw();
							event.reply("Joined your channel!");
					} else {
							event.reply("Don't need to join your channel as I'm already there with you!");
					}
			}
		});

	bot.on_ready([&bot](const dpp::ready_t& event) {
			if (dpp::run_once<struct register_bot_commands>()) {
					bot.global_command_create(dpp::slashcommand("ping", "Ping pong!", bot.me.id));
					bot.global_command_create(dpp::slashcommand("join", "Joins your voice channel.", bot.me.id));
			}
		});

	bot.start(dpp::st_wait);
}
