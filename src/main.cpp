#include <dpp/dpp.h>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <oggz/oggz.h>

const std::string BOT_TOKEN = "";

int main() {
	dpp::cluster bot(BOT_TOKEN);
	bot.on_log(dpp::utility::cout_logger());

	bot.on_slashcommand([](const dpp::slashcommand_t& event) {
		if (event.command.get_command_name() == "join") {
			dpp::guild* g = dpp::find_guild(event.command.guild_id);
			if (!g->connect_member_voice(event.command.get_issuing_user().id)){
				event.reply("You don't seem to be in a voice channel!");
				return;
			}
			event.reply("Joined your channel!");
		} else if (event.command.get_command_name() == "play") {
				dpp::voiceconn* v = event.from->get_voice(event.command.guild_id);

				if (!v || !v->voiceclient || !v->voiceclient->is_ready()) {
					event.reply("I'm already joined channel!");
					return;
				}
				OGGZ *track_og = oggz_open("/home/cry386i/Música/German Imperial music/Kanye West - YERIKA (Erika + Praise God).opus", OGGZ_READ);
				if (!track_og) {
					fprintf(stderr, "Error opening file\n");
					event.reply("There was an issue opening the file!");
					return;
				}
				oggz_set_read_callback(
						track_og, -1,
						[](OGGZ *oggz, oggz_packet *packet, long serialno,
							void *user_data) {
						dpp::voiceconn *voiceconn = (dpp::voiceconn *)user_data;
						voiceconn->voiceclient->send_audio_opus(packet->op.packet,
								packet->op.bytes);
						return 0;
						},
						(void *)v
				);
				while (v && v->voiceclient && !v->voiceclient->terminating) {
					static const constexpr long CHUNK_READ = BUFSIZ * 2;
					const long read_bytes = oggz_read(track_og, CHUNK_READ);

					if (!read_bytes) {
						break;
					}
				}
				oggz_close(track_og);

				event.reply("Playing the audio file!");
		}
	});

	bot.on_ready([&bot](const dpp::ready_t & event){
			if (dpp::run_once<struct register_bot_commands>()) {
				dpp::slashcommand joincommand("join", "Joins your voice channel.", bot.me.id);
				dpp::slashcommand playcommand("play", "Plays an ogg file.", bot.me.id);

				bot.global_bulk_command_create({ joincommand, playcommand });
			}
	});

	bot.start(dpp::st_wait);

	return 0;
}
