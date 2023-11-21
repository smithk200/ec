FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_Trigger_CompletedGymPuzzle::
	addobject 9, MAP_FORTREE_CITY_GYM
	clearflag FLAG_FORTREE_GYM_NPC
	releaseall
	end

FortreeCity_Gym_EventScript_WarpDude::
	lock
	faceplayer
	msgbox FortreeCity_Gym_WarpDude_AskToWarp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FortreeCity_Gym_WarpDude_No
	warp MAP_FORTREE_CITY_GYM, 15, 4
	release
	end


FortreeCity_Gym_EventScript_Ned::
	setvar VAR_MUGSHOT_ID, MUGSHOT_NED
	trainerbattle_single TRAINER_NED_1, FortreeCity_Gym_Text_NedIntro, FortreeCity_Gym_Text_NedDefeat, FortreeCity_Gym_EventScript_NedDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM40, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_NedDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	setflag FLAG_FUNDAMENTALISTS
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM40
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM40
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM40
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_NED_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_WarpDude_No::
	msgbox FortreeCity_Gym_WarpDude_TextNo, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Fortree Gym Leader Ned is\n"
	.string "a master of Flying-type Pokémon.\p"
	.string "He's waiting at the back of this Gym,\n"
	.string "behind the rotating doors.\p"
	.string "He's waiting for new challengers\n"
	.string "who will follow Jesus, like him!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "You did it!\n"
	.string "You've achieved liftoff!$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Behold the elegant battle style of\n"
	.string "Bird Pokémon!$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "You…\n"
	.string "You're strong…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "A Trainer has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our Leader?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "The lovers of Bird Pokémon and\n"
	.string "God aspire to join this Gym.\p"
	.string "As a brother of Christ,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "The world is huge, and there are\n"
	.string "countless tough Trainers.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "There's no need for Ned, our Gym\n"
	.string "Leader, to deal with you!\p"
	.string "I'm plenty good enough for you!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "Ned, I…\n"
	.string "I lost!$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "Ned is holy and he's strong.\n"
	.string "He's the ultimate Leader!\p"
	.string "Priase be!$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "Ned taught me personally!\n"
	.string "Praise God! Praise God!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "I'm actually an atheist!$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Please don't tell Ned I\n"
	.string "said that...$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "When Ned takes to battle, his face\n"
	.string "shines with determination.\p"
	.string "I'm not letting you witness that\n"
	.string "holy sight!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Praise be!\n"
	.string "All hail Leader Ned.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "You'd better watch it!\n"
	.string "Make sure you read your Bible,\l"
	.string "lest Ned kicks you out!$"

FortreeCity_Gym_Text_DariusIntro:
	.string "There's more to life than\n"
	.string "Flying-type Pokémon!\p"
	.string "You do know that, right?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "No, my Tripsius...$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our Leader\l"
	.string "Ned's Pokémon are all holy.$"

FortreeCity_Gym_Text_NedIntro:
	.string "Hidey-ho, neighbor!\p"
	.string "I'm the leader of Fortree Gym!\p"
	.string "I read my Bible every day and have\n"
	.string "taken a vow to serve the LORD in\l"
	.string "everything I do!\p"
	.string "I pray to the almighty LORD\n"
	.string "that I will defeat you!\p"
	.string "Praise be to God!$"

FortreeCity_Gym_Text_NedDefeat:
	.string "God, why have you forsaken me?\p"
	.string "You put up a real good fight!\p"
	.string "Well, then, neighbor, I will\n"
	.string "give you this Gym Badge.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} received the Cross Badge\n"
	.string "from Ned.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "With the Cross Badge, all Pokémon up\n"
	.string "to LV 70, even those received through\l"
	.string "trades, will obey your every command.\p"
	.string "And this…\n"
	.string "This is a gift from the LORD.$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "TM40 contains Aerial Ace.\p"
	.string "It's an always accurate attack\n"
	.string "that hits without fail, just\l"
	.string "like our LORD!\p"
	.string "Praise Him!!$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registered Gym Leader Ned\n"
	.string "in the Pokénav.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Though I lost to you, I will remain\n"
	.string "devoted to my LORD GOD.$"

FortreeCity_Gym_Text_GymStatue:
	.string "Fortree City Pokémon Gym$"
	.string "Ned's Certified Trainers:\n"
	.string "Fry$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "Fortree City Pokémon Gym\p"
	.string "Ned's Certified Trainers:\n"
	.string "Fry, {PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "Ned: Hello, neighbor! I see\n"
	.string "you have returned.\p"
	.string "You got to be the Champion? Neat!\p"
	.string "I hope you haven't forgotten to\n"
	.string "read your Bible!\p"
	.string "God, give me the strength.\p"
	.string "to defeat you!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "God, you have forsaken me again!$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "Ned: Even though I have lost,\n"
	.string "my spirit remains with the LORD.\p"
	.string "God will give me the strength to\n"
	.string "defeat you once again.\p"
	.string "All hail the LORD!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "Ned: Please return with two Pokémon\n"
	.string "at least, per the Will of the Lord.$"

FortreeCity_Gym_WarpDude_AskToWarp:
	.string "Do you want me to warp you to\n"
	.string "Gym Leader Ned?$"

FortreeCity_Gym_WarpDude_TextNo:
	.string "Okay then!$"
