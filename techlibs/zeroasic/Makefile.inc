
OBJS += techlibs/zeroasic/synth_fpga.o techlibs/zeroasic/obs_clean.o

$(eval $(call add_share_file,share/zeroasic/z1000/techlib,techlibs/zeroasic/z1000/techlib/bram_memory_map_empty.txt))
$(eval $(call add_share_file,share/zeroasic/z1000/techlib,techlibs/zeroasic/z1000/techlib/tech_bram_empty.v))
$(eval $(call add_share_file,share/zeroasic/z1000/techlib,techlibs/zeroasic/z1000/techlib/tech_dsp_empty.v))
$(eval $(call add_share_file,share/zeroasic/z1000/techlib,techlibs/zeroasic/z1000/techlib/tech_flops.v))

$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/area_lut4.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/area_lut4_high_effort.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/delay_lut4.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/delay_lut4_high_effort.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/default_lut4.scr))

$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/area_lut6.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/area_lut6x2.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/delay_lut6.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/delay_lut6x2.scr))
$(eval $(call add_share_file,share/zeroasic/opt_scripts,techlibs/zeroasic/opt_scripts/default_lut6.scr))

$(eval $(call add_share_file,share/zeroasic/ff_models,techlibs/zeroasic/ff_models/dff.v))
$(eval $(call add_share_file,share/zeroasic/ff_models,techlibs/zeroasic/ff_models/dffe.v))
$(eval $(call add_share_file,share/zeroasic/ff_models,techlibs/zeroasic/ff_models/dffr.v))
$(eval $(call add_share_file,share/zeroasic/ff_models,techlibs/zeroasic/ff_models/dffer.v))




