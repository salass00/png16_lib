/*
 * AmigaOS shared library implementation of libpng 1.6.x
 *
 * Copyright (C) 2017 Fredrik Wikstrom <fredrik@a500.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS `AS IS'
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <interfaces/png16.h>

asm("\t.section\t\".text\"\n"
	"\t.align\t2\n"
	"\t.globl\t__CallPNG16\n"
	"\t.type\t__CallPNG16, @function\n"
	"__CallPNG16:\n"
	"\tlis\t%r11,IPNG16@ha\n"
	"\tlwz\t%r0,IPNG16@l(%r11)\n"
	"\tlwzx\t%r11,%r12,%r0\n"
	"\tmtctr\t%r11\n"
	"\tbctr\n"
	"\t.size\t__CallPNG16, .-__CallPNG16");

#define PNG16Call(function, offset) \
asm("\t.section\t\".text\"\n" \
	"\t.align\t2\n" \
	"\t.globl\t" #function "\n" \
	"\t.type\t" #function ", @function\n" \
	#function ":\n" \
	"\tli\t%r12," #offset "\n" \
	"\tb\t__CallPNG16\n" \
	"\t.size\t" #function ", .-" #function);

PNG16Call(png_access_version_number, 76)
PNG16Call(png_set_sig_bytes, 80)
PNG16Call(png_sig_cmp, 84)
PNG16Call(png_create_read_struct, 88)
PNG16Call(png_create_write_struct, 92)
PNG16Call(png_get_compression_buffer_size, 96)
PNG16Call(png_set_compression_buffer_size, 100)
PNG16Call(png_set_longjmp_fn, 104)
PNG16Call(png_longjmp, 108)
PNG16Call(png_create_read_struct_2, 112)
PNG16Call(png_create_write_struct_2, 116)
PNG16Call(png_write_sig, 120)
PNG16Call(png_write_chunk, 124)
PNG16Call(png_write_chunk_start, 128)
PNG16Call(png_write_chunk_data, 132)
PNG16Call(png_write_chunk_end, 136)
PNG16Call(png_create_info_struct, 140)
PNG16Call(png_write_info_before_PLTE, 144)
PNG16Call(png_write_info, 148)
PNG16Call(png_read_info, 152)
PNG16Call(png_convert_to_rfc1123_buffer, 156)
PNG16Call(png_convert_from_struct_tm, 160)
PNG16Call(png_convert_from_time_t, 164)
PNG16Call(png_set_expand, 168)
PNG16Call(png_set_expand_gray_1_2_4_to_8, 172)
PNG16Call(png_set_palette_to_rgb, 176)
PNG16Call(png_set_tRNS_to_alpha, 180)
PNG16Call(png_set_expand_16, 184)
PNG16Call(png_set_bgr, 188)
PNG16Call(png_set_gray_to_rgb, 192)
PNG16Call(png_set_rgb_to_gray, 196)
PNG16Call(png_set_rgb_to_gray_fixed, 200)
PNG16Call(png_get_rgb_to_gray_status, 204)
PNG16Call(png_build_grayscale_palette, 208)
PNG16Call(png_set_alpha_mode, 212)
PNG16Call(png_set_alpha_mode_fixed, 216)
PNG16Call(png_set_strip_alpha, 220)
PNG16Call(png_set_swap_alpha, 224)
PNG16Call(png_set_invert_alpha, 228)
PNG16Call(png_set_filler, 232)
PNG16Call(png_set_add_alpha, 236)
PNG16Call(png_set_swap, 240)
PNG16Call(png_set_packing, 244)
PNG16Call(png_set_packswap, 248)
PNG16Call(png_set_shift, 252)
PNG16Call(png_set_interlace_handling, 256)
PNG16Call(png_set_invert_mono, 260)
PNG16Call(png_set_background, 264)
PNG16Call(png_set_background_fixed, 268)
PNG16Call(png_set_scale_16, 272)
PNG16Call(png_set_strip_16, 276)
PNG16Call(png_set_quantize, 280)
PNG16Call(png_set_gamma, 284)
PNG16Call(png_set_gamma_fixed, 288)
PNG16Call(png_set_flush, 292)
PNG16Call(png_write_flush, 296)
PNG16Call(png_start_read_image, 300)
PNG16Call(png_read_update_info, 304)
PNG16Call(png_read_rows, 308)
PNG16Call(png_read_row, 312)
PNG16Call(png_write_row, 316)
PNG16Call(png_write_rows, 320)
PNG16Call(png_write_image, 324)
PNG16Call(png_write_end, 328)
PNG16Call(png_read_end, 332)
PNG16Call(png_destroy_info_struct, 336)
PNG16Call(png_destroy_read_struct, 340)
PNG16Call(png_destroy_write_struct, 344)
PNG16Call(png_set_crc_action, 348)
PNG16Call(png_set_filter, 352)
PNG16Call(png_set_filter_heuristics, 356)
PNG16Call(png_set_filter_heuristics_fixed, 360)
PNG16Call(png_set_compression_level, 364)
PNG16Call(png_set_compression_mem_level, 368)
PNG16Call(png_set_compression_strategy, 372)
PNG16Call(png_set_compression_window_bits, 376)
PNG16Call(png_set_compression_method, 380)
PNG16Call(png_set_text_compression_level, 384)
PNG16Call(png_set_text_compression_mem_level, 388)
PNG16Call(png_set_text_compression_strategy, 392)
PNG16Call(png_set_text_compression_window_bits, 396)
PNG16Call(png_set_text_compression_method, 400)
PNG16Call(png_init_io, 404)
PNG16Call(png_set_error_fn, 408)
PNG16Call(png_get_error_ptr, 412)
PNG16Call(png_set_write_fn, 416)
PNG16Call(png_set_read_fn, 420)
PNG16Call(png_get_io_ptr, 424)
PNG16Call(png_set_read_status_fn, 428)
PNG16Call(png_set_write_status_fn, 432)
PNG16Call(png_set_mem_fn, 436)
PNG16Call(png_get_mem_ptr, 440)
PNG16Call(png_set_read_user_transform_fn, 444)
PNG16Call(png_set_write_user_transform_fn, 448)
PNG16Call(png_set_user_transform_info, 452)
PNG16Call(png_get_user_transform_ptr, 456)
PNG16Call(png_get_current_row_number, 460)
PNG16Call(png_get_current_pass_number, 464)
PNG16Call(png_set_read_user_chunk_fn, 468)
PNG16Call(png_get_user_chunk_ptr, 472)
PNG16Call(png_set_progressive_read_fn, 476)
PNG16Call(png_get_progressive_ptr, 480)
PNG16Call(png_process_data, 484)
PNG16Call(png_process_data_pause, 488)
PNG16Call(png_process_data_skip, 492)
PNG16Call(png_progressive_combine_row, 496)
PNG16Call(png_malloc, 500)
PNG16Call(png_calloc, 504)
PNG16Call(png_malloc_warn, 508)
PNG16Call(png_free, 512)
PNG16Call(png_free_data, 516)
PNG16Call(png_data_freer, 520)
PNG16Call(png_error, 524)
PNG16Call(png_chunk_error, 528)
PNG16Call(png_warning, 532)
PNG16Call(png_chunk_warning, 536)
PNG16Call(png_benign_error, 540)
PNG16Call(png_chunk_benign_error, 544)
PNG16Call(png_set_benign_errors, 548)
PNG16Call(png_get_valid, 552)
PNG16Call(png_get_rowbytes, 556)
PNG16Call(png_get_rows, 560)
PNG16Call(png_set_rows, 564)
PNG16Call(png_get_channels, 568)
PNG16Call(png_get_image_width, 572)
PNG16Call(png_get_image_height, 576)
PNG16Call(png_get_bit_depth, 580)
PNG16Call(png_get_color_type, 584)
PNG16Call(png_get_filter_type, 588)
PNG16Call(png_get_interlace_type, 592)
PNG16Call(png_get_compression_type, 596)
PNG16Call(png_get_pixels_per_meter, 600)
PNG16Call(png_get_x_pixels_per_meter, 604)
PNG16Call(png_get_y_pixels_per_meter, 608)
PNG16Call(png_get_pixel_aspect_ratio, 612)
PNG16Call(png_get_pixel_aspect_ratio_fixed, 616)
PNG16Call(png_get_x_offset_pixels, 620)
PNG16Call(png_get_y_offset_pixels, 624)
PNG16Call(png_get_x_offset_microns, 628)
PNG16Call(png_get_y_offset_microns, 632)
PNG16Call(png_get_signature, 636)
PNG16Call(png_get_bKGD, 640)
PNG16Call(png_set_bKGD, 644)
PNG16Call(png_get_cHRM, 648)
PNG16Call(png_get_cHRM_XYZ, 652)
PNG16Call(png_get_cHRM_fixed, 656)
PNG16Call(png_get_cHRM_XYZ_fixed, 660)
PNG16Call(png_set_cHRM, 664)
PNG16Call(png_set_cHRM_XYZ, 668)
PNG16Call(png_set_cHRM_fixed, 672)
PNG16Call(png_set_cHRM_XYZ_fixed, 676)
PNG16Call(png_get_eXIf, 680)
PNG16Call(png_set_eXIf, 684)
PNG16Call(png_get_eXIf_1, 688)
PNG16Call(png_set_eXIf_1, 692)
PNG16Call(png_get_gAMA, 696)
PNG16Call(png_get_gAMA_fixed, 700)
PNG16Call(png_set_gAMA, 704)
PNG16Call(png_set_gAMA_fixed, 708)
PNG16Call(png_get_hIST, 712)
PNG16Call(png_set_hIST, 716)
PNG16Call(png_get_IHDR, 720)
PNG16Call(png_set_IHDR, 724)
PNG16Call(png_get_oFFs, 728)
PNG16Call(png_set_oFFs, 732)
PNG16Call(png_get_pCAL, 736)
PNG16Call(png_set_pCAL, 740)
PNG16Call(png_get_pHYs, 744)
PNG16Call(png_set_pHYs, 748)
PNG16Call(png_get_PLTE, 752)
PNG16Call(png_set_PLTE, 756)
PNG16Call(png_get_sBIT, 760)
PNG16Call(png_set_sBIT, 764)
PNG16Call(png_get_sRGB, 768)
PNG16Call(png_set_sRGB, 772)
PNG16Call(png_set_sRGB_gAMA_and_cHRM, 776)
PNG16Call(png_get_iCCP, 780)
PNG16Call(png_set_iCCP, 784)
PNG16Call(png_get_sPLT, 788)
PNG16Call(png_set_sPLT, 792)
PNG16Call(png_get_text, 796)
PNG16Call(png_set_text, 800)
PNG16Call(png_get_tIME, 804)
PNG16Call(png_set_tIME, 808)
PNG16Call(png_get_tRNS, 812)
PNG16Call(png_set_tRNS, 816)
PNG16Call(png_get_sCAL, 820)
PNG16Call(png_get_sCAL_fixed, 824)
PNG16Call(png_get_sCAL_s, 828)
PNG16Call(png_set_sCAL, 832)
PNG16Call(png_set_sCAL_fixed, 836)
PNG16Call(png_set_sCAL_s, 840)
PNG16Call(png_set_keep_unknown_chunks, 844)
PNG16Call(png_handle_as_unknown, 848)
PNG16Call(png_set_unknown_chunks, 852)
PNG16Call(png_set_unknown_chunk_location, 856)
PNG16Call(png_get_unknown_chunks, 860)
PNG16Call(png_set_invalid, 864)
PNG16Call(png_read_png, 868)
PNG16Call(png_write_png, 872)
PNG16Call(png_get_copyright, 876)
PNG16Call(png_get_header_ver, 880)
PNG16Call(png_get_header_version, 884)
PNG16Call(png_get_libpng_ver, 888)
PNG16Call(png_permit_mng_features, 892)
PNG16Call(png_set_user_limits, 896)
PNG16Call(png_get_user_width_max, 900)
PNG16Call(png_get_user_height_max, 904)
PNG16Call(png_set_chunk_cache_max, 908)
PNG16Call(png_get_chunk_cache_max, 912)
PNG16Call(png_set_chunk_malloc_max, 916)
PNG16Call(png_get_chunk_malloc_max, 920)
PNG16Call(png_get_pixels_per_inch, 924)
PNG16Call(png_get_x_pixels_per_inch, 928)
PNG16Call(png_get_y_pixels_per_inch, 932)
PNG16Call(png_get_x_offset_inches, 936)
PNG16Call(png_get_x_offset_inches_fixed, 940)
PNG16Call(png_get_y_offset_inches, 944)
PNG16Call(png_get_y_offset_inches_fixed, 948)
PNG16Call(png_get_pHYs_dpi, 952)
PNG16Call(png_get_io_state, 956)
PNG16Call(png_get_io_chunk_type, 960)
PNG16Call(png_get_uint_32, 964)
PNG16Call(png_get_uint_16, 968)
PNG16Call(png_get_int_32, 972)
PNG16Call(png_get_uint_31, 976)
PNG16Call(png_save_uint_32, 980)
PNG16Call(png_save_int_32, 984)
PNG16Call(png_save_uint_16, 988)
PNG16Call(png_set_check_for_invalid_index, 992)
PNG16Call(png_get_palette_max, 996)
PNG16Call(png_image_begin_read_from_file, 1000)
PNG16Call(png_image_begin_read_from_stdio, 1004)
PNG16Call(png_image_begin_read_from_memory, 1008)
PNG16Call(png_image_finish_read, 1012)
PNG16Call(png_image_free, 1016)
PNG16Call(png_image_write_to_file, 1020)
PNG16Call(png_image_write_to_stdio, 1024)
PNG16Call(png_image_write_to_memory, 1028)
PNG16Call(png_set_option, 1032)
