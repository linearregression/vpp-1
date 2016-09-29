/*
 * Copyright (c) 2016 Midokura SARL.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdbool.h>
#include <vppinfra/error.h>
#include <vnet/vnet.h>
#include <vnet/ip/ip.h>
#include <vlib/vlib.h>

typedef struct {
} fip64_main_t;

/*
 * MAP Error counters/messages
 */
#define foreach_fip64_error                             \
/* Must be first. */                                    \
_(NONE, "valid FIP64 packets")                          \
_(BAD_PROTOCOL, "bad protocol")                         \
_(ICMP, "unable to translate ICMP")                     \
_(ICMP_RELAY, "unable to relay ICMP")                   \
_(UNKNOWN, "unknown")                                   \
_(FRAGMENTED, "packet is a fragment")                   \
_(FRAGMENT_MEMORY, "could not cache fragment")	        \
_(FRAGMENT_MALFORMED, "fragment has unexpected format") \
_(FRAGMENT_DROPPED, "dropped cached fragment")          \
_(MALFORMED, "malformed packet")                        \
_(DF_SET, "can't fragment, DF set")

typedef enum {
#define _(sym,str) FIP64_ERROR_##sym,
  foreach_fip64_error
#undef _
  FIP64_N_ERROR,
} fip64_error_t;

u64 fip64_error_counter_get(u32 node_index, fip64_error_t fip64_error);
