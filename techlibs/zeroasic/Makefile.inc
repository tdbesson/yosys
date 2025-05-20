
OBJS += techlibs/zeroasic/synth_fpga.o techlibs/zeroasic/obs_clean.o techlibs/zeroasic/clk_domains.o techlibs/zeroasic/load_models.o

$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/bram_memory_map_empty.txt))
$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/tech_bram_empty.v))
$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/tech_dsp_empty.v))
$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/tech_flops.v))

$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/area_lut4.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/area_lut4_high_effort.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/delay_lut4.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/delay_lut4_high_effort.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/default_lut4.scr))

$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/area_lut6.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/area_lut6x2.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/delay_lut6.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/delay_lut6x2.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS,techlibs/zeroasic/ABC_SCRIPTS/default_lut6.scr))

$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dff.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffe.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffr.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffs.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffer.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffes.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffers.v))




