.set LOCALID_MATTHEW, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

LavaridgeTown_Gym_1F_Trigger_CompletedGymPuzzle::
	addobject 7, MAP_LAVARIDGE_TOWN_GYM_1F
	clearflag FLAG_LAVARIDGE_GYM_NPC
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_WarpDude::
	lock
	faceplayer
	msgbox LavaridgeTown_Gym_1F_WarpDude_AskToWarp, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FortreeCity_Gym_WarpDude_No
	warp MAP_LAVARIDGE_TOWN_GYM_1F, 13, 11
	release
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_MATTHEW, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_MATTHEW, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_MATTHEW, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	setvar VAR_MUGSHOT_ID, MUGSHOT_FLANNERY
	trainerbattle_single TRAINER_MOLLY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM50, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM50
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM50
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_MOLLY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Matthew::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_MATTHEW, LOCALID_MATTHEW, LavaridgeTown_Gym_1F_Text_MatthewIntro, LavaridgeTown_Gym_1F_Text_MatthewDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "Lavaridge's new Gym Leader\n"
	.string "ousted our old one, Flannery!\p"
	.string "She's only five years old, but\n"
	.string "her Pokémon are super strong.\p"
	.string "There will be a Pokémon\n"
	.string "that will suicide randomly.\p"
	.string "Be warned!\p"
	.string "Oh, and after you complete the\n"
	.string "Gym challenge, you'll see a\l"
	.string "helpful Trainer who will take you\l"
	.string "to the Gym Leader!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Yow! That was a scorching-hot battle!$"

LavaridgeTown_Gym_1F_Text_MatthewIntro:
	.string "Slugma balls!$"

LavaridgeTown_Gym_1F_Text_MatthewDefeat:
	.string "Even my Slugma army couldn't\n"
	.string "defeat you…$"

LavaridgeTown_Gym_1F_Text_MatthewPostBattle:
	.string "SLUGMA FOR THE WIN!!!\n"
	.string "LESSGO!!!!$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Have you heard of Poppy from\n"
	.string "Paldea? She's just as strong\l"
	.string "as our Gym Leader!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "I hope our Gym Leader flames you good!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Poppy should really get to\p"
	.string "know our Leader.$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Play with fire, and you get burned.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "You have no chance against\n"
	.string "against our Gym Leader!$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Your skill is real…\n"
	.string "But our Leader is strong.\p"
	.string "If you don't watch yourself, you'll\n"
	.string "get kicked in the ass.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Can your Pokémon withstand\n"
	.string "451-degree heat?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "It didn't burn hotly enough…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "The temperature of burning books is\n"
	.string "451 degrees.\p"
	.string "Read a book, and you die!\p"
	.string "-Fahrenheit 451$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "I smoke weed every single day!\n"
	.string "Bring it on!!!$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Fuck you!$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Just, piss off already!\n"
	.string "Lemme smoke my weed in peace!$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "I liked Flannery.\n"
	.string "She was so sexy!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "I was blinded by love…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Damn, I really wanted to date\n"
	.string "Flannery.\p"
	.string "Since our new Gym Leader is five\n"
	.string "years old, I can't date her.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "See how the flames blaze wildly?\n"
	.string "They flare in anticipation of my win!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Something didn't go right.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Well, so what? I say so what?\n"
	.string "I can walk on hot coals barefoot!\p"
	.string "…Don't even think about trying it!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "As much as I love mountains,\n"
	.string "I especially love volcanoes.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Well, it seems to me I lost without\n"
	.string "ever being in control.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "I stay here because I became a fan\n"
	.string "of Flannery's power.\p"
	.string "Huh?\p"
	.string "Flannery's not the Gym Leader\n"
	.string "anymore?$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Hi!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "You beat me.\n"
	.string "Here, take this.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} received the Fire Badge\n"
	.string "from Molly.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "If you have a Fire Badge, uh...\n"
	.string "I can't read yet.\l"
	.string "But I think it's something like\l"
	.string "Pokémon up to level 50 will\l"
	.string "obey you?\p"
	.string "And, it lets Pokémon use the HM move\n"
	.string "Strength outside of battle?\p"
	.string "Here, take this too.\n"
	.string "Even though I never used this move.$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "That TM50 contains Overheat.\p"
	.string "That move inflicts serious damage on\n"
	.string "the opponent.\p"
	.string "But it also sharply cuts the\n"
	.string "Special Attack of the Pokémon\l"
	.string "using it.\p"
	.string "It might not\n"
	.string "be suitable for longer battles.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Registered Gym Leader Molly\n"
	.string "in the Pokénav.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Go back to where your dad\n"
	.string "is the Gym Leader.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "Lavaridge Town Pokémon Gym\p"
	.string "Certified Trainers:\n"
	.string "Fry$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "Lavaridge Town Pokémon Gym\p"
	.string "Certified Trainers:\n"
	.string "Fry, {PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "Hello again!\p"
	.string "Let's battle!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "You beat me again!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "Let's battle again!\p"
	.string "Not right away, though!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "Molly: Bring at least two Pokémon,\n"
	.string "please!$"

LavaridgeTown_Gym_1F_WarpDude_AskToWarp:
	.string "Do you want me to warp you to\n"
	.string "the Gym Leader?$"
