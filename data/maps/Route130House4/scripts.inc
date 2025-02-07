Route130House4_MapScripts::
	.byte 0

Route130House4_EventScriptRoxanne_and_Tate::
	lock
	faceplayer
	msgbox Route130House4_Text_RoxanneandTateIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_ROXANNE_2, Route130House4_Text_RoxanneDefeat, TRAINER_TATE_2, Route130House4_Text_TateDefeat
	goto Route130House4_EventScriptCommonReceivedSSTicket
	release
	end
Route130House4_EventScriptBrawly_and_Norman::
	lock
	faceplayer
	msgbox Route130House4_Text_BrawlyandNormanIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_BRAWLY_2, Route130House4_Text_BrawlyDefeat, TRAINER_NORMAN_2, Route130House4_Text_NormanDefeat
	goto Route130House4_EventScriptCommonReceivedSSTicket
	release
	end
Route130House4_EventScriptBill_and_Bender::
	lock
	faceplayer
	msgbox Route130House4_Text_BillandBenderIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_WATTSON_2, Route130House4_Text_BillDefeat, TRAINER_JUAN_2, Route130House4_Text_BenderDefeat
	goto Route130House4_EventScriptCommonReceivedSSTicket
	release
	end
Route130House4_EventScriptMolly_andLiza::
	lock
	faceplayer
	msgbox Route130House4_Text_MollyandLizaIntro, MSGBOX_DEFAULT
	trainerbattle_two_trainers TRAINER_MOLLY_2, Route130House4_Text_MollyDefeat, TRAINER_LIZA_2, Route130House4_Text_LizaDefeat
	goto Route130House4_EventScriptCommonReceivedSSTicket
	release
	end
Route130House4_EventScriptNed::
	lock
	faceplayer
	trainerbattle_single TRAINER_NED_2, Route130House4_Text_NedIntro, Route130House4_Text_NedDefeat, Route130House4_EventScript_NedDefeated
	goto Route130House4_EventScriptCommonReceivedSSTicket
	release
	end

Route130House4_EventScriptCommonReceivedSSTicket::
	setflag FLAG_RECEIVED_SS_TICKET
	giveitem ITEM_SS_TICKET
	return


Route130House4_EventScript_NedDefeated::
	msgbox Route130_House4_NedPostBattle, MSGBOX_DEFAULT	
	release
	end

Route130House4_Text_RoxanneandTateIntro:
    .string "You are a strong Trainer!$"
        
Route130House4_Text_BrawlyandNormanIntro:
    .string "You are a strong Trainer!$"
        
Route130House4_Text_MollyandLizaIntro:
    .string "Molly: Hi!/n"
	.string "Liza: Hi!/n"
	.string "Molly: We are training together!/n"
	.string "Liza: We are going to be the best Gym Leader\l"
	.string "team!/p"
	.string "Molly and Liza: Let's do this!$"
        
Route130House4_Text_BillandBenderIntro:
    .string "You are a strong Trainer!$"
        
Route130House4_Text_NedIntro:
    .string "Hidey-ho, neighborino!\p"
	.string "The other Gym Leaders didn't want\n"
	.string "to partner with me.\p"
	.string "Something about how I worship God?\p"
	.string "No matter, because the LORD is here to\n"
	.string "give me victory over you!$"

Route130House4_Text_RoxanneDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_BrawlyDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_BillDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_MollyDefeat:
	.string "Okay.$" 
Route130House4_Text_NormanDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_TateDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_LizaDefeat:
	.string "Aw, this sucks!$" 
Route130House4_Text_BenderDefeat:
	.string "Aw, this sucks!$" 

Route130House4_Text_NedDefeat:
	.string "Aw, this sucks!$" 

Route130_House4_NedPostBattle:
	.string "I pray to God every day!$"
