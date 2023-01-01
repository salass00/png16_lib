/*
 * AmigaOS shared library implementation of libpng 1.6.x
 *
 * Copyright (C) 2017-2023 Fredrik Wikstrom <fredrik@a500.org>
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

#include "png16_vectors.h"

static const APTR main_v1_vectors[] =
{
	_main_Obtain,
	_main_Release,
	NULL,
	NULL,
	png_access_version_number,
	png_set_sig_bytes,
	png_sig_cmp,
	png_create_read_struct,
	png_create_write_struct,
	png_get_compression_buffer_size,
	png_set_compression_buffer_size,
	png_set_longjmp_fn,
	png_longjmp,
	png_create_read_struct_2,
	png_create_write_struct_2,
	png_write_sig,
	png_write_chunk,
	png_write_chunk_start,
	png_write_chunk_data,
	png_write_chunk_end,
	png_create_info_struct,
	png_write_info_before_PLTE,
	png_write_info,
	png_read_info,
	png_convert_to_rfc1123_buffer,
	png_convert_from_struct_tm,
	png_convert_from_time_t,
	png_set_expand,
	png_set_expand_gray_1_2_4_to_8,
	png_set_palette_to_rgb,
	png_set_tRNS_to_alpha,
	png_set_expand_16,
	png_set_bgr,
	png_set_gray_to_rgb,
	png_set_rgb_to_gray,
	png_set_rgb_to_gray_fixed,
	png_get_rgb_to_gray_status,
	png_build_grayscale_palette,
	png_set_alpha_mode,
	png_set_alpha_mode_fixed,
	png_set_strip_alpha,
	png_set_swap_alpha,
	png_set_invert_alpha,
	png_set_filler,
	png_set_add_alpha,
	png_set_swap,
	png_set_packing,
	png_set_packswap,
	png_set_shift,
	png_set_interlace_handling,
	png_set_invert_mono,
	png_set_background,
	png_set_background_fixed,
	png_set_scale_16,
	png_set_strip_16,
	png_set_quantize,
	png_set_gamma,
	png_set_gamma_fixed,
	png_set_flush,
	png_write_flush,
	png_start_read_image,
	png_read_update_info,
	png_read_rows,
	png_read_row,
	png_write_row,
	png_write_rows,
	png_write_image,
	png_write_end,
	png_read_end,
	png_destroy_info_struct,
	png_destroy_read_struct,
	png_destroy_write_struct,
	png_set_crc_action,
	png_set_filter,
	png_set_filter_heuristics,
	png_set_filter_heuristics_fixed,
	png_set_compression_level,
	png_set_compression_mem_level,
	png_set_compression_strategy,
	png_set_compression_window_bits,
	png_set_compression_method,
	png_set_text_compression_level,
	png_set_text_compression_mem_level,
	png_set_text_compression_strategy,
	png_set_text_compression_window_bits,
	png_set_text_compression_method,
	png_init_io,
	png_set_error_fn,
	png_get_error_ptr,
	png_set_write_fn,
	png_set_read_fn,
	png_get_io_ptr,
	png_set_read_status_fn,
	png_set_write_status_fn,
	png_set_mem_fn,
	png_get_mem_ptr,
	png_set_read_user_transform_fn,
	png_set_write_user_transform_fn,
	png_set_user_transform_info,
	png_get_user_transform_ptr,
	png_get_current_row_number,
	png_get_current_pass_number,
	png_set_read_user_chunk_fn,
	png_get_user_chunk_ptr,
	png_set_progressive_read_fn,
	png_get_progressive_ptr,
	png_process_data,
	png_process_data_pause,
	png_process_data_skip,
	png_progressive_combine_row,
	png_malloc,
	png_calloc,
	png_malloc_warn,
	png_free,
	png_free_data,
	png_data_freer,
	png_error,
	png_chunk_error,
	png_warning,
	png_chunk_warning,
	png_benign_error,
	png_chunk_benign_error,
	png_set_benign_errors,
	png_get_valid,
	png_get_rowbytes,
	png_get_rows,
	png_set_rows,
	png_get_channels,
	png_get_image_width,
	png_get_image_height,
	png_get_bit_depth,
	png_get_color_type,
	png_get_filter_type,
	png_get_interlace_type,
	png_get_compression_type,
	png_get_pixels_per_meter,
	png_get_x_pixels_per_meter,
	png_get_y_pixels_per_meter,
	png_get_pixel_aspect_ratio,
	png_get_pixel_aspect_ratio_fixed,
	png_get_x_offset_pixels,
	png_get_y_offset_pixels,
	png_get_x_offset_microns,
	png_get_y_offset_microns,
	png_get_signature,
	png_get_bKGD,
	png_set_bKGD,
	png_get_cHRM,
	png_get_cHRM_XYZ,
	png_get_cHRM_fixed,
	png_get_cHRM_XYZ_fixed,
	png_set_cHRM,
	png_set_cHRM_XYZ,
	png_set_cHRM_fixed,
	png_set_cHRM_XYZ_fixed,
	png_get_eXIf,
	png_set_eXIf,
	png_get_eXIf_1,
	png_set_eXIf_1,
	png_get_gAMA,
	png_get_gAMA_fixed,
	png_set_gAMA,
	png_set_gAMA_fixed,
	png_get_hIST,
	png_set_hIST,
	png_get_IHDR,
	png_set_IHDR,
	png_get_oFFs,
	png_set_oFFs,
	png_get_pCAL,
	png_set_pCAL,
	png_get_pHYs,
	png_set_pHYs,
	png_get_PLTE,
	png_set_PLTE,
	png_get_sBIT,
	png_set_sBIT,
	png_get_sRGB,
	png_set_sRGB,
	png_set_sRGB_gAMA_and_cHRM,
	png_get_iCCP,
	png_set_iCCP,
	png_get_sPLT,
	png_set_sPLT,
	png_get_text,
	png_set_text,
	png_get_tIME,
	png_set_tIME,
	png_get_tRNS,
	png_set_tRNS,
	png_get_sCAL,
	png_get_sCAL_fixed,
	png_get_sCAL_s,
	png_set_sCAL,
	png_set_sCAL_fixed,
	png_set_sCAL_s,
	png_set_keep_unknown_chunks,
	png_handle_as_unknown,
	png_set_unknown_chunks,
	png_set_unknown_chunk_location,
	png_get_unknown_chunks,
	png_set_invalid,
	png_read_png,
	png_write_png,
	png_get_copyright,
	png_get_header_ver,
	png_get_header_version,
	png_get_libpng_ver,
	png_permit_mng_features,
	png_set_user_limits,
	png_get_user_width_max,
	png_get_user_height_max,
	png_set_chunk_cache_max,
	png_get_chunk_cache_max,
	png_set_chunk_malloc_max,
	png_get_chunk_malloc_max,
	png_get_pixels_per_inch,
	png_get_x_pixels_per_inch,
	png_get_y_pixels_per_inch,
	png_get_x_offset_inches,
	png_get_x_offset_inches_fixed,
	png_get_y_offset_inches,
	png_get_y_offset_inches_fixed,
	png_get_pHYs_dpi,
	png_get_io_state,
	png_get_io_chunk_type,
	png_get_uint_32,
	png_get_uint_16,
	png_get_int_32,
	png_get_uint_31,
	png_save_uint_32,
	png_save_int_32,
	png_save_uint_16,
	png_set_check_for_invalid_index,
	png_get_palette_max,
	png_image_begin_read_from_file,
	png_image_begin_read_from_stdio,
	png_image_begin_read_from_memory,
	png_image_finish_read,
	png_image_free,
	png_image_write_to_file,
	png_image_write_to_stdio,
	png_image_write_to_memory,
	png_set_option,
	png_read_image,
	(APTR)-1
};

