/**
 * \file config_struct.h
 * \author Petr Kramolis <kramolis@cesnet.cz>
 * \brief
 *
 * Copyright (C) 2011 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * ALTERNATIVELY, provided that this notice is retained in full, this
 * product may be distributed under the terms of the GNU General Public
 * License (GPL) version 2 or later, in which case the provisions
 * of the GPL apply INSTEAD OF those given above.
 *
 * This software is provided ``as is, and any express or implied
 * warranties, including, but not limited to, the implied warranties of
 * merchantability and fitness for a particular purpose are disclaimed.
 * In no event shall the company or contributors be liable for any
 * direct, indirect, incidental, special, exemplary, or consequential
 * damages (including, but not limited to, procurement of substitute
 * goods or services; loss of use, data, or profits; or business
 * interruption) however caused and on any theory of liability, whether
 * in contract, strict liability, or tort (including negligence or
 * otherwise) arising in any way out of the use of this software, even
 * if advised of the possibility of such damage.
 *
 */

#ifndef CONFIG_STRUCT_H_
#define CONFIG_STRUCT_H_


#include <string>
#include <map>
#include <vector>

#include "nfstore.h"
#include "record_map.h"

class templateTable;

struct nfdumpConfig{
	/* this stores data buffers based on received templates
	 * (template id -> extension map */
	std::map<uint32_t,NfdumpFile*> *files;

	/* buffer allocated size */
	uint bufferSize;

	/* time_window specifies time interval for storage directory rotation */
	int timeWindow;

	/* path to directory where should be storage directory flushed */
	std::string sysDir;

	/* current window directory */
	std::string windowDir;

	/* user prefix for output files*/
	std::string prefix;

	/* indentation string for nffiles*/
	std::string ident;

	/* lzo compression of records */
	bool compression;

	/* time of last flush (used for time based rotation,
	 * name is based on start of interval not its end!) */
	time_t lastFlush;
};

#endif /* CONFIG_STRUCT_H_ */
