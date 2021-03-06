/*
 * Copyright (c) 2015 Cisco and/or its affiliates.
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

#ifndef __included_vnet_l2_classify_h__
#define __included_vnet_l2_classify_h__

#include <vlib/vlib.h>
#include <vnet/vnet.h>
#include <vnet/pg/pg.h>
#include <vnet/ethernet/ethernet.h>
#include <vnet/ethernet/packet.h>
#include <vnet/ip/ip_packet.h>
#include <vnet/ip/ip4_packet.h>
#include <vnet/ip/ip6_packet.h>
#include <vlib/cli.h>
#include <vnet/l2/l2_input.h>
#include <vnet/l2/feat_bitmap.h>
#include <vppinfra/error.h>
#include <vppinfra/hash.h>
#include <vppinfra/cache.h>

#include <vnet/classify/vnet_classify.h>

typedef enum
{
  L2_CLASSIFY_NEXT_DROP,
  L2_CLASSIFY_NEXT_ETHERNET_INPUT,
  L2_CLASSIFY_NEXT_IP4_INPUT,
  L2_CLASSIFY_NEXT_IP6_INPUT,
  L2_CLASSIFY_NEXT_LI,
  L2_CLASSIFY_N_NEXT,
} l2_classify_next_t;

typedef enum
{
  L2_CLASSIFY_TABLE_IP4,
  L2_CLASSIFY_TABLE_IP6,
  L2_CLASSIFY_TABLE_OTHER,
  L2_CLASSIFY_N_TABLES,
} l2_classify_table_id_t;

typedef struct
{

  /* Next nodes for each feature */
  u32 feat_next_node_index[32];

  /* Per-address-family classifier table vectors */
  u32 *classify_table_index_by_sw_if_index[L2_CLASSIFY_N_TABLES];

  /* convenience variables */
  vlib_main_t *vlib_main;
  vnet_main_t *vnet_main;
  vnet_classify_main_t *vnet_classify_main;
} l2_classify_main_t;

l2_classify_main_t l2_classify_main;

extern vlib_node_registration_t l2_classify_node;

void vnet_l2_classify_enable_disable (u32 sw_if_index, int enable_disable);

int vnet_l2_classify_set_tables (u32 sw_if_index, u32 ip4_table_index,
				 u32 ip6_table_index, u32 other_table_index);

#endif /* __included_vnet_l2_classify_h__ */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
