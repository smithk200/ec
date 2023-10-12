	.align 2
voicegroup197:: @am using placeholder voices for sounds until I find the real sound
	voice_keysplit_all voicegroup196 @universal drums
	voice_keysplit voicegroup005, KeySplitTable1 @piano
	voice_directsound 60, 0, DirectSoundWaveData_steinway_b_piano, 255, 188, 103, 165 @bright piano
	voice_keysplit voicegroup005, KeySplitTable1 @honky tonk
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_detuned_ep1_low, 255, 188, 103, 165
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_detuned_ep1_low, 255, 188, 103, 165
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 165, 128, 204 @harpsichord
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 165, 128, 204 @clavi
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 165, 128, 204 @celeste
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_glockenspiel, 255, 165, 128, 204 @glockenspiel
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_glockenspiel, 255, 165, 128, 204 @music box
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_xylophone, 255, 0, 255, 16 @vibraphone
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_xylophone, 255, 0, 255, 16 @marimba
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_xylophone, 255, 0, 255, 16 @xylophone
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_tubular_bell, 255, 226, 0, 99
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 165, 128, 204 @dulcimer
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 249, 0, 165 @organ
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 249, 0, 165 @organ
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 249, 0, 165 @organ
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 249, 0, 165 @organ
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_church_organ3_low, 255, 249, 0, 165 @organ
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_accordion, 255, 249, 0, 165 @accordion
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_accordion, 255, 249, 0, 165 @harmonica
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_accordion_duplicate, 255, 249, 0, 165 @accordion
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 249, 0, 165 @nylon guitar
    voice_directsound 60, 0, DirectSoundWaveData_sc88pro_nylon_str_guitar, 255, 165, 128, 204 @steel guitar TODO
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 255, 165, 128, 204 @jazz guitar TODO
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 255, 165, 128, 204 @clean electric guitar TODO
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 255, 165, 128, 204 @muted electric guitar TODO
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 255, 0, 255, 127 @overdrive
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_distortion_guitar_high, 255, 0, 255, 127 @distortion
	voice_directsound 60, 0, DirectSoundWaveData_unused_guitar_separates_power_chord, 255, 165, 154, 165 @harmonics TODO
	voice_directsound 60, 0, DirectSoundWaveData_trinity_30303_mega_bass, 255, 0, 255, 127 @acoustic bass
	voice_directsound 60, 0, DirectSoundWaveData_fingered_bass, 255, 0, 255, 127 @finger bass
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 253, 0, 188 @picked bass
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 253, 0, 188 @fretless bass
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_slap_bass, 255, 253, 0, 188 @slap bass 1
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_slap_bass, 255, 253, 0, 188 @slap bass 2
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_synth_bass, 255, 0, 224, 165 @synth bass 1
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_synth_bass, 255, 0, 224, 165 @synth bass 2
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_84, 255, 226, 0, 99 @violin
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_84, 255, 226, 0, 99 @viola
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_60, 255, 226, 0, 99 @cello
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_string_ensemble_60, 255, 226, 0, 99 @contrabass
	voice_keysplit voicegroup006, KeySplitTable2 @tremolo strings
	voice_keysplit voicegroup006, KeySplitTable2 @pizz. strings
	voice_keysplit voicegroup006, KeySplitTable1 @orchestra strings
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_timpani, 255, 226, 0, 99 @timpani
	voice_keysplit voicegroup006, KeySplitTable2 @string ens. 1
	voice_keysplit voicegroup006, KeySplitTable2 @string ens. 2
	voice_keysplit voicegroup006, KeySplitTable2 @synth strings 1
	voice_keysplit voicegroup006, KeySplitTable2 @synth strings 2
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 226, 0, 99 @aahs
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 226, 0, 99 @oohs
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 226, 0, 99 @synth voice
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_orchestra_snare, 255, 226, 0, 99 @orchestra hit TODO
	voice_keysplit voicegroup198, KeySplitTable6 @trumpet
	voice_keysplit voicegroup008, KeySplitTable2 @trombone
	voice_keysplit voicegroup008, KeySplitTable2 @tuba
	voice_keysplit voicegroup198, KeySplitTable6 @muted trumpet
	voice_keysplit voicegroup009, KeySplitTable5 @french horn
	voice_keysplit voicegroup198, KeySplitTable6 @brass
	voice_keysplit voicegroup198, KeySplitTable6 @synth brass
	voice_keysplit voicegroup198, KeySplitTable6 @synth brass
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @soprano sax
	voice_keysplit voicegroup192, KeySplitTable2 @alto sax
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @tenor sax
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0 @bari sax
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_oboe, 255, 255, 0, 165 @oboe
	voice_directsound 60, 0, DirectSoundWaveData_unused_sd90_oboe, 255, 255, 0, 165 @english horn
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_oboe, 255, 255, 0, 165 @bassoon
	voice_square_1 60, 0, 0, 2, 0, 0, 15, 0
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 0, 255, 16 @piccolo
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 0, 255, 16 @flute
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 0, 255, 16 @recorder
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_shakuhachi_low, 255, 165, 180, 165 @pan flute
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_shakuhachi, 255, 165, 180, 165 @blown bottle
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_shakuhachi_low, 255, 165, 180, 165 @shakuhachi
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_whistle, 255, 0, 255, 16 @whistle
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_flute, 255, 0, 255, 16 @ocarina
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_square_wave, 255, 255, 0, 99 @square
	voice_directsound 60, 0, DirectSoundWaveData_saw_synth, 255, 255, 0, 99 @saw
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_shakuhachi_low, 255, 165, 180, 165 @calliope
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_overdrive_guitar, 255, 0, 255, 127 @chiff
	voice_directsound 60, 0, DirectSoundWaveData_sd90_classical_distortion_guitar_high, 255, 0, 255, 127 @charang
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 226, 0, 99 @voice
	voice_directsound 60, 0, DirectSoundWaveData_unused_guitar_separates_power_chord, 255, 165, 154, 165 @fifths TODO
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @bass + lead TODO
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @new age TODO
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @warmth
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @polysynth
	voice_directsound 60, 0, DirectSoundWaveData_classical_choir_voice_ahhs, 255, 0, 255, 16 @choir
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @bowed
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @metallic
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @halo
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @sweep
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @rain
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @soundtrack
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @crystal
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @atmosphere
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @brightness
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @goblins
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @echoes
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16 @sci-fi
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16
	voice_directsound 60, 0, DirectSoundWaveData_sc88pro_fretless_bass, 255, 0, 255, 16

