Route130House4_MapScripts::
	.byte 0

Route130House4_EventScriptRoxanne_and_Tate::
        trainerbattle_two_trainers TRAINER_ROXANNE_2, Route130House4_Text_RoxanneDefeat, TRAINER_TATE_2, Route130House4_Text_TateDefeat
        release
        end
Route130House4_EventScriptBrawly_and_Norman::
        trainerbattle_two_trainers TRAINER_BRAWLY_2, Route130House4_Text_BrawlyDefeat, TRAINER_NORMAN_2, Route130House4_Text_NormanDefeat
        release
        end
Route130House4_EventScriptBill_and_Bender::
        trainerbattle_two_trainers TRAINER_WATTSON_2, Route130House4_Text_BillDefeat, TRAINER_JUAN_2, Route130House4_Text_BenderDefeat
        release
        end
Route130House4_EventScriptMolly_andLiza::
        trainerbattle_two_trainers TRAINER_MOLLY_2, Route130House4_Text_MollyDefeat, TRAINER_LIZA_2, Route130House4_Text_LizaDefeat
        release
        end
Route130House4_EventScriptNed::
        trainerbattle_single TRAINER_NED_2, Route130House4_Text_NedIntro, Route130House4_Text_NedDefeat, Route130House4_EventScript_NedDefeated
        release
        end

Route130House4_EventScript_NedDefeated::
	msgbox Route130_House4_NedPostBattle, MSGBOX_DEFAULT	
	release
	end

Route130House4_Text_RoxanneDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_BrawlyDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_BillDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_MollyDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_NormanDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_TateDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_LizaDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_BenderDefeat:
	.string "Aw, this sucks!$" 

Route130House4_Text_NedIntro:
	.string "Hi, neighbor!$"

Route130House4_Text_NedDefeat:
	.string "Aw, this sucks!$" 

Route130_House4_NedPostBattle:
	.string "I pray to God every day!$"
