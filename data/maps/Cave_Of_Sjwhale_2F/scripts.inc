Cave_Of_Sjwhale_2F_MapScripts::
	.byte 0

Cave_Of_Sjwhale_EventScript_Alice::
	trainerbattle_single TRAINER_ALICE_2, Cave_Of_Sjwhale_Text_AliceIntro, Cave_Of_Sjwhale_Text_AliceDefeat
	msgbox Cave_Of_Sjwhale_Text_AlicePostBattle, MSGBOX_AUTOCLOSE
	end

Cave_Of_Sjwhale_Text_AliceIntro:
    .string "Did you know there are more than\n"
    .string "one hundred genders?\p"
    .string "I identify as an omnisexual\n"
    .string "pangender demidemon!$"

Cave_Of_Sjwhale_Text_AliceDefeat:
    .string "How dare you say there are only\n"
    .string "two genders? You are a racist,\l"
    .string "sexist transphobe who is only\l"
    .string "a big, immature baby!$"

Cave_Of_Sjwhale_Text_AlicePostBattle:
    .string "PLEASE, VALIDATE MY IDENTITY!!!$"
