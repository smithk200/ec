Route130_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route130_OnTransition
	.byte 0

Route130_OnTransition:
	call_if_ge VAR_SOOTOPOLIS_CITY_STATE, 4, Route130_EventScript_CheckSetAbnormalWeather
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, Route130_EventScript_SetMirageIslandLayout
	setflag FLAG_TEMP_11
	setflag FLAG_TEMP_12
	setflag FLAG_TEMP_13
	setflag FLAG_TEMP_14
	setflag FLAG_TEMP_15
	setflag FLAG_TEMP_16
	setflag FLAG_TEMP_17
	setflag FLAG_TEMP_18
	setflag FLAG_TEMP_19
	setflag FLAG_TEMP_1A
	setflag FLAG_TEMP_1B
	setflag FLAG_TEMP_1C
	setflag FLAG_TEMP_1D
	setflag FLAG_TEMP_1E
	setflag FLAG_TEMP_1F
	setmaplayoutindex LAYOUT_ROUTE130
	setflag FLAG_VISITED_AN_ISLAND 
	end

AnIsland_EventScript_Woman::
	lock
	faceplayer
	msgbox AnIsland_Text_Woman, MSGBOX_AUTOCLOSE
	release
	end

AnIsland_EventScript_Man::
	lock
	faceplayer
	msgbox AnIsland_Text_Man, MSGBOX_AUTOCLOSE
	release
	end

Route130_EventScript_SetMirageIslandLayout::
	setmaplayoutindex LAYOUT_ROUTE130_MIRAGE_ISLAND
	end

Route130_EventScript_CheckSetAbnormalWeather::
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	return

Route130_EventScript_Rodney::
	trainerbattle_single TRAINER_RODNEY, Route130_Text_RodneyIntro, Route130_Text_RodneyDefeat
	msgbox Route130_Text_RodneyPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Katie:: @put her in the Cave of Sjwhale
	trainerbattle_single TRAINER_KATIE, Route130_Text_KatieIntro, Route130_Text_KatieDefeat
	msgbox Route130_Text_KatiePostBattle, MSGBOX_AUTOCLOSE
	end

Route130_EventScript_Santiago:: @put him in the Cave of Sjwhale, but may need to change his gender
	trainerbattle_single TRAINER_SANTIAGO, Route130_Text_SantiagoIntro, Route130_Text_SantiagoDefeat
	msgbox Route130_Text_SantiagoPostBattle, MSGBOX_AUTOCLOSE
	end

Route130_Sign_AnIsland::
	msgbox Route130_Text_AnIsland, MSGBOX_DEFAULT
	release
	end

Route130_GymLeadersHouse::
	msgbox Route130_Text_GymLeadersHouse, MSGBOX_DEFAULT
	release
	end

Route130_Event_Script_CaveIsClosed::
	faceplayer
	msgbox Route130_Text_CaveIsClosed, MSGBOX_DEFAULT
	release
	end

Route130_Text_AnIsland:
	.string "An Island\n"
	.string "The Cave of Sjwhale is also here.\p"
	.string "An island created by Team Mag-\p"
	.string "(There are swastikas and graffiti\n"
	.string "drawn all over the sign.)$"

Route130_Text_GymLeadersHouse:
	.string "Gym Leader Resort House\p"
	.string "Notice: Only people who have defeated\n"
	.string "the Champion may enter here!$"

Route130_Text_CaveIsClosed:
	.string "Philip J. Fry: The Cave of\n"
	.string "Sjwhale is closed right now.\p"
	.string "I don't want to get in the way\n"
	.string "of the feminists!$"

AnIsland_Text_Woman:
	.string "This island was only formed\n"
	.string "recently. What is Team Magma\l"
	.string "up to now?$"

AnIsland_Text_Man:
	.string "They say that the legendary\n"
	.string "Pokémon Adesign lurks in the\l"
	.string "Cave of Sjwhale.\p"
	.string "However, the creator is too busy\n"
	.string "with school to actually work on it.\p"
	.string "So it's closed now.$"
