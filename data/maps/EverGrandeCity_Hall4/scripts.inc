EverGrandeCity_Hall4_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall4_OnWarp
	.byte 0

EverGrandeCity_Hall4_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall4_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall4_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_Philip_J_Fry::
	trainerbattle_single TRAINER_FRY_EVER_GRANDE, Philip_J_Fry_2_Intro, Philip_J_Fry_2_Defeat, EventScriptEverGrandeCityFryDefeated
	msgbox Philip_J_Fry_2_Post_Battle, MSGBOX_DEFAULT
	release
	end

EventScriptEverGrandeCityFryDefeated::
	msgbox Philip_J_Fry_2_Post_Battle, MSGBOX_DEFAULT
	release
	end

Philip_J_Fry_2_Intro:
	.string "Hi there! Are you ready to face\n"
	.string "the Champion yet?\p"
	.string "I faced her, and I couldn't defeat\n"
	.string "her yet. Her Garchomp was what got\l"
	.string "me in the end.\p"
	.string "But I'll be here to test your skill\n"
	.string "against the mighty Champion!\p"
	.string "NOW WHO'S READY TO RUMBLE!!!$"
Philip_J_Fry_2_Defeat:
	.string "You really ARE ready!\n"
	.string "Can't wait to see you defeat her!$"
Philip_J_Fry_2_Post_Battle:
	.string "Beat the Champion for me, okay?$"
