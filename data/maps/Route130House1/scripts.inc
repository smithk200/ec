Route130House1_MapScripts::
	.byte 0

Route130_House1_EventScriptMan::
    lock
    faceplayer
    msgbox Route130_House1_TextMan, MSGBOX_DEFAULT
	release
	end

Route130_House1_TextMan:
    .string "I just got the new game\n"
    .string "Super Mario Bros. Wonder!\p"
    .string "I can't wait to get the\n"
    .string "Elephant Fruit!\p"
    .string "Wowie zowie!\p"
    .string "Oh?\p"
    .string "Is Team Aqua ruining the world with\n"
    .string "their rain?\p"
    .string "I don't want to hear about it.$"
