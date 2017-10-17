/*===========================================================================
*
*                            PUBLIC DOMAIN NOTICE
*               National Center for Biotechnology Information
*
*  This software/database is a "United States Government Work" under the
*  terms of the United States Copyright Act.  It was written as part of
*  the author's official duties as a United States Government employee and
*  thus cannot be copyrighted.  This software/database is freely available
*  to the public for use. The National Library of Medicine and the U.S.
*  Government have not placed any restriction on its use or reproduction.
*
*  Although all reasonable efforts have been taken to ensure the accuracy
*  and reliability of the software and data, the NLM and the U.S.
*  Government do not and cannot warrant the performance or results that
*  may be obtained by using this software or data. The NLM and the U.S.
*  Government disclaim all warranties, express or implied, including
*  warranties of performance, merchantability or fitness for any particular
*  purpose.
*
*  Please cite the author in any work or product based on this material.
*
* ===========================================================================
*
*/

#ifndef _h_join_
#define _h_join_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _h_klib_rc_
#include <klib/rc.h>
#endif

#ifndef _h_klib_text_
#include <klib/text.h>
#endif

#ifndef _h_kfs_directory_
#include <kfs/directory.h>
#endif

#ifndef _h_atomic_
#include <atomic.h>
#endif

#ifndef _h_helper_
#include "helper.h"
#endif

typedef struct join_params
{
    KDirectory * dir;
    const char * accession;
    const char * lookup_filename;
    const char * index_filename;
    const char * output_filename;
    tmp_id * tmp_id;
    VNamelist * joined_files;
    struct KFastDumpCleanupTask * cleanup_task;
    atomic_t   * join_progress;
    size_t buf_size, cur_cache, num_threads;
    int64_t first_row;
    uint64_t row_count;
    bool show_progress;
    format_t fmt;
} join_params;

rc_t execute_join( const join_params * jp );

#ifdef __cplusplus
}
#endif

#endif
