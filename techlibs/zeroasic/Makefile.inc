
OBJS += techlibs/zeroasic/synth_fpga.o techlibs/zeroasic/obs_clean.o techlibs/zeroasic/clk_domains.o techlibs/zeroasic/load_models.o techlibs/zeroasic/report_stat.o techlibs/zeroasic/time_chrono.o

$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/bram_memory_map_empty.txt))
$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/tech_bram_empty.v))
$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/tech_dsp_empty.v))
$(eval $(call add_share_file,share/zeroasic/Z1000/techlib,techlibs/zeroasic/Z1000/techlib/tech_flops.v))


#########################
# LUT4
#########################
#

#V1
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V1,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V1/area_lut4.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V1,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V1/delay_lut4.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V1,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V1/default_lut4.scr))

#V2
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V2,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V2/default_lut4.scr))

$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V2,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V2/delay_lut4.scr))

#V3
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V3,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V3/delay_lut4.scr))

#V4
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT4/V4,techlibs/zeroasic/ABC_SCRIPTS/LUT4/V4/delay_lut4.scr))


#########################
# LUT6
#########################
#
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT6/V1,techlibs/zeroasic/ABC_SCRIPTS/LUT6/V1/area_lut6.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT6/V1,techlibs/zeroasic/ABC_SCRIPTS/LUT6/V1/delay_lut6.scr))
$(eval $(call add_share_file,share/zeroasic/ABC_SCRIPTS/LUT6/V1,techlibs/zeroasic/ABC_SCRIPTS/LUT6/V1/default_lut6.scr))

# MODELS
#
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dff.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffe.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffr.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffs.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffrs.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffer.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffes.v))
$(eval $(call add_share_file,share/zeroasic/FF_MODELS,techlibs/zeroasic/FF_MODELS/dffers.v))




