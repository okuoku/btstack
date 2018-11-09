/*
 * Copyright (C) 2014 BlueKitchen GmbH
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 * 4. Any redistribution, use, or modification is done solely for
 *    personal benefit and not for any commercial purpose or for
 *    monetary gain.
 *
 * THIS SOFTWARE IS PROVIDED BY BLUEKITCHEN GMBH AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL MATTHIAS
 * RINGWALD OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * Please inquire about commercial licensing options at 
 * contact@bluekitchen-gmbh.com
 *
 */

#define BTSTACK_FILE__ "btstack_memory.c"


/*
 *  btstack_memory.h
 *
 *  @brief BTstack memory management via configurable memory pools
 *
 *  @note code generated by tool/btstack_memory_generator.py
 *  @note returnes buffers are initialized with 0
 *
 */

#include "btstack_memory.h"
#include "btstack_memory_pool.h"

#include <stdlib.h>



// MARK: hci_connection_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_HCI_CONNECTIONS)
    #if defined(MAX_NO_HCI_CONNECTIONS)
        #error "Deprecated MAX_NO_HCI_CONNECTIONS defined instead of MAX_NR_HCI_CONNECTIONS. Please update your btstack_config.h to use MAX_NR_HCI_CONNECTIONS."
    #else
        #define MAX_NR_HCI_CONNECTIONS 0
    #endif
#endif

#ifdef MAX_NR_HCI_CONNECTIONS
#if MAX_NR_HCI_CONNECTIONS > 0
static hci_connection_t hci_connection_storage[MAX_NR_HCI_CONNECTIONS];
static btstack_memory_pool_t hci_connection_pool;
hci_connection_t * btstack_memory_hci_connection_get(void){
    void * buffer = btstack_memory_pool_get(&hci_connection_pool);
    if (buffer){
        memset(buffer, 0, sizeof(hci_connection_t));
    }
    return (hci_connection_t *) buffer;
}
void btstack_memory_hci_connection_free(hci_connection_t *hci_connection){
    btstack_memory_pool_free(&hci_connection_pool, hci_connection);
}
#else
hci_connection_t * btstack_memory_hci_connection_get(void){
    return NULL;
}
void btstack_memory_hci_connection_free(hci_connection_t *hci_connection){
    // silence compiler warning about unused parameter in a portable way
    (void) hci_connection;
};
#endif
#elif defined(HAVE_MALLOC)
hci_connection_t * btstack_memory_hci_connection_get(void){
    void * buffer = malloc(sizeof(hci_connection_t));
    if (buffer){
        memset(buffer, 0, sizeof(hci_connection_t));
    }
    return (hci_connection_t *) buffer;
}
void btstack_memory_hci_connection_free(hci_connection_t *hci_connection){
    free(hci_connection);
}
#endif



// MARK: l2cap_service_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_L2CAP_SERVICES)
    #if defined(MAX_NO_L2CAP_SERVICES)
        #error "Deprecated MAX_NO_L2CAP_SERVICES defined instead of MAX_NR_L2CAP_SERVICES. Please update your btstack_config.h to use MAX_NR_L2CAP_SERVICES."
    #else
        #define MAX_NR_L2CAP_SERVICES 0
    #endif
#endif

#ifdef MAX_NR_L2CAP_SERVICES
#if MAX_NR_L2CAP_SERVICES > 0
static l2cap_service_t l2cap_service_storage[MAX_NR_L2CAP_SERVICES];
static btstack_memory_pool_t l2cap_service_pool;
l2cap_service_t * btstack_memory_l2cap_service_get(void){
    void * buffer = btstack_memory_pool_get(&l2cap_service_pool);
    if (buffer){
        memset(buffer, 0, sizeof(l2cap_service_t));
    }
    return (l2cap_service_t *) buffer;
}
void btstack_memory_l2cap_service_free(l2cap_service_t *l2cap_service){
    btstack_memory_pool_free(&l2cap_service_pool, l2cap_service);
}
#else
l2cap_service_t * btstack_memory_l2cap_service_get(void){
    return NULL;
}
void btstack_memory_l2cap_service_free(l2cap_service_t *l2cap_service){
    // silence compiler warning about unused parameter in a portable way
    (void) l2cap_service;
};
#endif
#elif defined(HAVE_MALLOC)
l2cap_service_t * btstack_memory_l2cap_service_get(void){
    void * buffer = malloc(sizeof(l2cap_service_t));
    if (buffer){
        memset(buffer, 0, sizeof(l2cap_service_t));
    }
    return (l2cap_service_t *) buffer;
}
void btstack_memory_l2cap_service_free(l2cap_service_t *l2cap_service){
    free(l2cap_service);
}
#endif


// MARK: l2cap_channel_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_L2CAP_CHANNELS)
    #if defined(MAX_NO_L2CAP_CHANNELS)
        #error "Deprecated MAX_NO_L2CAP_CHANNELS defined instead of MAX_NR_L2CAP_CHANNELS. Please update your btstack_config.h to use MAX_NR_L2CAP_CHANNELS."
    #else
        #define MAX_NR_L2CAP_CHANNELS 0
    #endif
#endif

#ifdef MAX_NR_L2CAP_CHANNELS
#if MAX_NR_L2CAP_CHANNELS > 0
static l2cap_channel_t l2cap_channel_storage[MAX_NR_L2CAP_CHANNELS];
static btstack_memory_pool_t l2cap_channel_pool;
l2cap_channel_t * btstack_memory_l2cap_channel_get(void){
    void * buffer = btstack_memory_pool_get(&l2cap_channel_pool);
    if (buffer){
        memset(buffer, 0, sizeof(l2cap_channel_t));
    }
    return (l2cap_channel_t *) buffer;
}
void btstack_memory_l2cap_channel_free(l2cap_channel_t *l2cap_channel){
    btstack_memory_pool_free(&l2cap_channel_pool, l2cap_channel);
}
#else
l2cap_channel_t * btstack_memory_l2cap_channel_get(void){
    return NULL;
}
void btstack_memory_l2cap_channel_free(l2cap_channel_t *l2cap_channel){
    // silence compiler warning about unused parameter in a portable way
    (void) l2cap_channel;
};
#endif
#elif defined(HAVE_MALLOC)
l2cap_channel_t * btstack_memory_l2cap_channel_get(void){
    void * buffer = malloc(sizeof(l2cap_channel_t));
    if (buffer){
        memset(buffer, 0, sizeof(l2cap_channel_t));
    }
    return (l2cap_channel_t *) buffer;
}
void btstack_memory_l2cap_channel_free(l2cap_channel_t *l2cap_channel){
    free(l2cap_channel);
}
#endif


#ifdef ENABLE_CLASSIC

// MARK: rfcomm_multiplexer_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_RFCOMM_MULTIPLEXERS)
    #if defined(MAX_NO_RFCOMM_MULTIPLEXERS)
        #error "Deprecated MAX_NO_RFCOMM_MULTIPLEXERS defined instead of MAX_NR_RFCOMM_MULTIPLEXERS. Please update your btstack_config.h to use MAX_NR_RFCOMM_MULTIPLEXERS."
    #else
        #define MAX_NR_RFCOMM_MULTIPLEXERS 0
    #endif
#endif

#ifdef MAX_NR_RFCOMM_MULTIPLEXERS
#if MAX_NR_RFCOMM_MULTIPLEXERS > 0
static rfcomm_multiplexer_t rfcomm_multiplexer_storage[MAX_NR_RFCOMM_MULTIPLEXERS];
static btstack_memory_pool_t rfcomm_multiplexer_pool;
rfcomm_multiplexer_t * btstack_memory_rfcomm_multiplexer_get(void){
    void * buffer = btstack_memory_pool_get(&rfcomm_multiplexer_pool);
    if (buffer){
        memset(buffer, 0, sizeof(rfcomm_multiplexer_t));
    }
    return (rfcomm_multiplexer_t *) buffer;
}
void btstack_memory_rfcomm_multiplexer_free(rfcomm_multiplexer_t *rfcomm_multiplexer){
    btstack_memory_pool_free(&rfcomm_multiplexer_pool, rfcomm_multiplexer);
}
#else
rfcomm_multiplexer_t * btstack_memory_rfcomm_multiplexer_get(void){
    return NULL;
}
void btstack_memory_rfcomm_multiplexer_free(rfcomm_multiplexer_t *rfcomm_multiplexer){
    // silence compiler warning about unused parameter in a portable way
    (void) rfcomm_multiplexer;
};
#endif
#elif defined(HAVE_MALLOC)
rfcomm_multiplexer_t * btstack_memory_rfcomm_multiplexer_get(void){
    void * buffer = malloc(sizeof(rfcomm_multiplexer_t));
    if (buffer){
        memset(buffer, 0, sizeof(rfcomm_multiplexer_t));
    }
    return (rfcomm_multiplexer_t *) buffer;
}
void btstack_memory_rfcomm_multiplexer_free(rfcomm_multiplexer_t *rfcomm_multiplexer){
    free(rfcomm_multiplexer);
}
#endif


// MARK: rfcomm_service_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_RFCOMM_SERVICES)
    #if defined(MAX_NO_RFCOMM_SERVICES)
        #error "Deprecated MAX_NO_RFCOMM_SERVICES defined instead of MAX_NR_RFCOMM_SERVICES. Please update your btstack_config.h to use MAX_NR_RFCOMM_SERVICES."
    #else
        #define MAX_NR_RFCOMM_SERVICES 0
    #endif
#endif

#ifdef MAX_NR_RFCOMM_SERVICES
#if MAX_NR_RFCOMM_SERVICES > 0
static rfcomm_service_t rfcomm_service_storage[MAX_NR_RFCOMM_SERVICES];
static btstack_memory_pool_t rfcomm_service_pool;
rfcomm_service_t * btstack_memory_rfcomm_service_get(void){
    void * buffer = btstack_memory_pool_get(&rfcomm_service_pool);
    if (buffer){
        memset(buffer, 0, sizeof(rfcomm_service_t));
    }
    return (rfcomm_service_t *) buffer;
}
void btstack_memory_rfcomm_service_free(rfcomm_service_t *rfcomm_service){
    btstack_memory_pool_free(&rfcomm_service_pool, rfcomm_service);
}
#else
rfcomm_service_t * btstack_memory_rfcomm_service_get(void){
    return NULL;
}
void btstack_memory_rfcomm_service_free(rfcomm_service_t *rfcomm_service){
    // silence compiler warning about unused parameter in a portable way
    (void) rfcomm_service;
};
#endif
#elif defined(HAVE_MALLOC)
rfcomm_service_t * btstack_memory_rfcomm_service_get(void){
    void * buffer = malloc(sizeof(rfcomm_service_t));
    if (buffer){
        memset(buffer, 0, sizeof(rfcomm_service_t));
    }
    return (rfcomm_service_t *) buffer;
}
void btstack_memory_rfcomm_service_free(rfcomm_service_t *rfcomm_service){
    free(rfcomm_service);
}
#endif


// MARK: rfcomm_channel_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_RFCOMM_CHANNELS)
    #if defined(MAX_NO_RFCOMM_CHANNELS)
        #error "Deprecated MAX_NO_RFCOMM_CHANNELS defined instead of MAX_NR_RFCOMM_CHANNELS. Please update your btstack_config.h to use MAX_NR_RFCOMM_CHANNELS."
    #else
        #define MAX_NR_RFCOMM_CHANNELS 0
    #endif
#endif

#ifdef MAX_NR_RFCOMM_CHANNELS
#if MAX_NR_RFCOMM_CHANNELS > 0
static rfcomm_channel_t rfcomm_channel_storage[MAX_NR_RFCOMM_CHANNELS];
static btstack_memory_pool_t rfcomm_channel_pool;
rfcomm_channel_t * btstack_memory_rfcomm_channel_get(void){
    void * buffer = btstack_memory_pool_get(&rfcomm_channel_pool);
    if (buffer){
        memset(buffer, 0, sizeof(rfcomm_channel_t));
    }
    return (rfcomm_channel_t *) buffer;
}
void btstack_memory_rfcomm_channel_free(rfcomm_channel_t *rfcomm_channel){
    btstack_memory_pool_free(&rfcomm_channel_pool, rfcomm_channel);
}
#else
rfcomm_channel_t * btstack_memory_rfcomm_channel_get(void){
    return NULL;
}
void btstack_memory_rfcomm_channel_free(rfcomm_channel_t *rfcomm_channel){
    // silence compiler warning about unused parameter in a portable way
    (void) rfcomm_channel;
};
#endif
#elif defined(HAVE_MALLOC)
rfcomm_channel_t * btstack_memory_rfcomm_channel_get(void){
    void * buffer = malloc(sizeof(rfcomm_channel_t));
    if (buffer){
        memset(buffer, 0, sizeof(rfcomm_channel_t));
    }
    return (rfcomm_channel_t *) buffer;
}
void btstack_memory_rfcomm_channel_free(rfcomm_channel_t *rfcomm_channel){
    free(rfcomm_channel);
}
#endif



// MARK: btstack_link_key_db_memory_entry_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES)
    #if defined(MAX_NO_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES)
        #error "Deprecated MAX_NO_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES defined instead of MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES. Please update your btstack_config.h to use MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES."
    #else
        #define MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES 0
    #endif
#endif

#ifdef MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES
#if MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES > 0
static btstack_link_key_db_memory_entry_t btstack_link_key_db_memory_entry_storage[MAX_NR_BTSTACK_LINK_KEY_DB_MEMORY_ENTRIES];
static btstack_memory_pool_t btstack_link_key_db_memory_entry_pool;
btstack_link_key_db_memory_entry_t * btstack_memory_btstack_link_key_db_memory_entry_get(void){
    void * buffer = btstack_memory_pool_get(&btstack_link_key_db_memory_entry_pool);
    if (buffer){
        memset(buffer, 0, sizeof(btstack_link_key_db_memory_entry_t));
    }
    return (btstack_link_key_db_memory_entry_t *) buffer;
}
void btstack_memory_btstack_link_key_db_memory_entry_free(btstack_link_key_db_memory_entry_t *btstack_link_key_db_memory_entry){
    btstack_memory_pool_free(&btstack_link_key_db_memory_entry_pool, btstack_link_key_db_memory_entry);
}
#else
btstack_link_key_db_memory_entry_t * btstack_memory_btstack_link_key_db_memory_entry_get(void){
    return NULL;
}
void btstack_memory_btstack_link_key_db_memory_entry_free(btstack_link_key_db_memory_entry_t *btstack_link_key_db_memory_entry){
    // silence compiler warning about unused parameter in a portable way
    (void) btstack_link_key_db_memory_entry;
};
#endif
#elif defined(HAVE_MALLOC)
btstack_link_key_db_memory_entry_t * btstack_memory_btstack_link_key_db_memory_entry_get(void){
    void * buffer = malloc(sizeof(btstack_link_key_db_memory_entry_t));
    if (buffer){
        memset(buffer, 0, sizeof(btstack_link_key_db_memory_entry_t));
    }
    return (btstack_link_key_db_memory_entry_t *) buffer;
}
void btstack_memory_btstack_link_key_db_memory_entry_free(btstack_link_key_db_memory_entry_t *btstack_link_key_db_memory_entry){
    free(btstack_link_key_db_memory_entry);
}
#endif



// MARK: bnep_service_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_BNEP_SERVICES)
    #if defined(MAX_NO_BNEP_SERVICES)
        #error "Deprecated MAX_NO_BNEP_SERVICES defined instead of MAX_NR_BNEP_SERVICES. Please update your btstack_config.h to use MAX_NR_BNEP_SERVICES."
    #else
        #define MAX_NR_BNEP_SERVICES 0
    #endif
#endif

#ifdef MAX_NR_BNEP_SERVICES
#if MAX_NR_BNEP_SERVICES > 0
static bnep_service_t bnep_service_storage[MAX_NR_BNEP_SERVICES];
static btstack_memory_pool_t bnep_service_pool;
bnep_service_t * btstack_memory_bnep_service_get(void){
    void * buffer = btstack_memory_pool_get(&bnep_service_pool);
    if (buffer){
        memset(buffer, 0, sizeof(bnep_service_t));
    }
    return (bnep_service_t *) buffer;
}
void btstack_memory_bnep_service_free(bnep_service_t *bnep_service){
    btstack_memory_pool_free(&bnep_service_pool, bnep_service);
}
#else
bnep_service_t * btstack_memory_bnep_service_get(void){
    return NULL;
}
void btstack_memory_bnep_service_free(bnep_service_t *bnep_service){
    // silence compiler warning about unused parameter in a portable way
    (void) bnep_service;
};
#endif
#elif defined(HAVE_MALLOC)
bnep_service_t * btstack_memory_bnep_service_get(void){
    void * buffer = malloc(sizeof(bnep_service_t));
    if (buffer){
        memset(buffer, 0, sizeof(bnep_service_t));
    }
    return (bnep_service_t *) buffer;
}
void btstack_memory_bnep_service_free(bnep_service_t *bnep_service){
    free(bnep_service);
}
#endif


// MARK: bnep_channel_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_BNEP_CHANNELS)
    #if defined(MAX_NO_BNEP_CHANNELS)
        #error "Deprecated MAX_NO_BNEP_CHANNELS defined instead of MAX_NR_BNEP_CHANNELS. Please update your btstack_config.h to use MAX_NR_BNEP_CHANNELS."
    #else
        #define MAX_NR_BNEP_CHANNELS 0
    #endif
#endif

#ifdef MAX_NR_BNEP_CHANNELS
#if MAX_NR_BNEP_CHANNELS > 0
static bnep_channel_t bnep_channel_storage[MAX_NR_BNEP_CHANNELS];
static btstack_memory_pool_t bnep_channel_pool;
bnep_channel_t * btstack_memory_bnep_channel_get(void){
    void * buffer = btstack_memory_pool_get(&bnep_channel_pool);
    if (buffer){
        memset(buffer, 0, sizeof(bnep_channel_t));
    }
    return (bnep_channel_t *) buffer;
}
void btstack_memory_bnep_channel_free(bnep_channel_t *bnep_channel){
    btstack_memory_pool_free(&bnep_channel_pool, bnep_channel);
}
#else
bnep_channel_t * btstack_memory_bnep_channel_get(void){
    return NULL;
}
void btstack_memory_bnep_channel_free(bnep_channel_t *bnep_channel){
    // silence compiler warning about unused parameter in a portable way
    (void) bnep_channel;
};
#endif
#elif defined(HAVE_MALLOC)
bnep_channel_t * btstack_memory_bnep_channel_get(void){
    void * buffer = malloc(sizeof(bnep_channel_t));
    if (buffer){
        memset(buffer, 0, sizeof(bnep_channel_t));
    }
    return (bnep_channel_t *) buffer;
}
void btstack_memory_bnep_channel_free(bnep_channel_t *bnep_channel){
    free(bnep_channel);
}
#endif



// MARK: hfp_connection_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_HFP_CONNECTIONS)
    #if defined(MAX_NO_HFP_CONNECTIONS)
        #error "Deprecated MAX_NO_HFP_CONNECTIONS defined instead of MAX_NR_HFP_CONNECTIONS. Please update your btstack_config.h to use MAX_NR_HFP_CONNECTIONS."
    #else
        #define MAX_NR_HFP_CONNECTIONS 0
    #endif
#endif

#ifdef MAX_NR_HFP_CONNECTIONS
#if MAX_NR_HFP_CONNECTIONS > 0
static hfp_connection_t hfp_connection_storage[MAX_NR_HFP_CONNECTIONS];
static btstack_memory_pool_t hfp_connection_pool;
hfp_connection_t * btstack_memory_hfp_connection_get(void){
    void * buffer = btstack_memory_pool_get(&hfp_connection_pool);
    if (buffer){
        memset(buffer, 0, sizeof(hfp_connection_t));
    }
    return (hfp_connection_t *) buffer;
}
void btstack_memory_hfp_connection_free(hfp_connection_t *hfp_connection){
    btstack_memory_pool_free(&hfp_connection_pool, hfp_connection);
}
#else
hfp_connection_t * btstack_memory_hfp_connection_get(void){
    return NULL;
}
void btstack_memory_hfp_connection_free(hfp_connection_t *hfp_connection){
    // silence compiler warning about unused parameter in a portable way
    (void) hfp_connection;
};
#endif
#elif defined(HAVE_MALLOC)
hfp_connection_t * btstack_memory_hfp_connection_get(void){
    void * buffer = malloc(sizeof(hfp_connection_t));
    if (buffer){
        memset(buffer, 0, sizeof(hfp_connection_t));
    }
    return (hfp_connection_t *) buffer;
}
void btstack_memory_hfp_connection_free(hfp_connection_t *hfp_connection){
    free(hfp_connection);
}
#endif



// MARK: service_record_item_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_SERVICE_RECORD_ITEMS)
    #if defined(MAX_NO_SERVICE_RECORD_ITEMS)
        #error "Deprecated MAX_NO_SERVICE_RECORD_ITEMS defined instead of MAX_NR_SERVICE_RECORD_ITEMS. Please update your btstack_config.h to use MAX_NR_SERVICE_RECORD_ITEMS."
    #else
        #define MAX_NR_SERVICE_RECORD_ITEMS 0
    #endif
#endif

#ifdef MAX_NR_SERVICE_RECORD_ITEMS
#if MAX_NR_SERVICE_RECORD_ITEMS > 0
static service_record_item_t service_record_item_storage[MAX_NR_SERVICE_RECORD_ITEMS];
static btstack_memory_pool_t service_record_item_pool;
service_record_item_t * btstack_memory_service_record_item_get(void){
    void * buffer = btstack_memory_pool_get(&service_record_item_pool);
    if (buffer){
        memset(buffer, 0, sizeof(service_record_item_t));
    }
    return (service_record_item_t *) buffer;
}
void btstack_memory_service_record_item_free(service_record_item_t *service_record_item){
    btstack_memory_pool_free(&service_record_item_pool, service_record_item);
}
#else
service_record_item_t * btstack_memory_service_record_item_get(void){
    return NULL;
}
void btstack_memory_service_record_item_free(service_record_item_t *service_record_item){
    // silence compiler warning about unused parameter in a portable way
    (void) service_record_item;
};
#endif
#elif defined(HAVE_MALLOC)
service_record_item_t * btstack_memory_service_record_item_get(void){
    void * buffer = malloc(sizeof(service_record_item_t));
    if (buffer){
        memset(buffer, 0, sizeof(service_record_item_t));
    }
    return (service_record_item_t *) buffer;
}
void btstack_memory_service_record_item_free(service_record_item_t *service_record_item){
    free(service_record_item);
}
#endif



// MARK: avdtp_stream_endpoint_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_AVDTP_STREAM_ENDPOINTS)
    #if defined(MAX_NO_AVDTP_STREAM_ENDPOINTS)
        #error "Deprecated MAX_NO_AVDTP_STREAM_ENDPOINTS defined instead of MAX_NR_AVDTP_STREAM_ENDPOINTS. Please update your btstack_config.h to use MAX_NR_AVDTP_STREAM_ENDPOINTS."
    #else
        #define MAX_NR_AVDTP_STREAM_ENDPOINTS 0
    #endif
#endif

#ifdef MAX_NR_AVDTP_STREAM_ENDPOINTS
#if MAX_NR_AVDTP_STREAM_ENDPOINTS > 0
static avdtp_stream_endpoint_t avdtp_stream_endpoint_storage[MAX_NR_AVDTP_STREAM_ENDPOINTS];
static btstack_memory_pool_t avdtp_stream_endpoint_pool;
avdtp_stream_endpoint_t * btstack_memory_avdtp_stream_endpoint_get(void){
    void * buffer = btstack_memory_pool_get(&avdtp_stream_endpoint_pool);
    if (buffer){
        memset(buffer, 0, sizeof(avdtp_stream_endpoint_t));
    }
    return (avdtp_stream_endpoint_t *) buffer;
}
void btstack_memory_avdtp_stream_endpoint_free(avdtp_stream_endpoint_t *avdtp_stream_endpoint){
    btstack_memory_pool_free(&avdtp_stream_endpoint_pool, avdtp_stream_endpoint);
}
#else
avdtp_stream_endpoint_t * btstack_memory_avdtp_stream_endpoint_get(void){
    return NULL;
}
void btstack_memory_avdtp_stream_endpoint_free(avdtp_stream_endpoint_t *avdtp_stream_endpoint){
    // silence compiler warning about unused parameter in a portable way
    (void) avdtp_stream_endpoint;
};
#endif
#elif defined(HAVE_MALLOC)
avdtp_stream_endpoint_t * btstack_memory_avdtp_stream_endpoint_get(void){
    void * buffer = malloc(sizeof(avdtp_stream_endpoint_t));
    if (buffer){
        memset(buffer, 0, sizeof(avdtp_stream_endpoint_t));
    }
    return (avdtp_stream_endpoint_t *) buffer;
}
void btstack_memory_avdtp_stream_endpoint_free(avdtp_stream_endpoint_t *avdtp_stream_endpoint){
    free(avdtp_stream_endpoint);
}
#endif



// MARK: avdtp_connection_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_AVDTP_CONNECTIONS)
    #if defined(MAX_NO_AVDTP_CONNECTIONS)
        #error "Deprecated MAX_NO_AVDTP_CONNECTIONS defined instead of MAX_NR_AVDTP_CONNECTIONS. Please update your btstack_config.h to use MAX_NR_AVDTP_CONNECTIONS."
    #else
        #define MAX_NR_AVDTP_CONNECTIONS 0
    #endif
#endif

#ifdef MAX_NR_AVDTP_CONNECTIONS
#if MAX_NR_AVDTP_CONNECTIONS > 0
static avdtp_connection_t avdtp_connection_storage[MAX_NR_AVDTP_CONNECTIONS];
static btstack_memory_pool_t avdtp_connection_pool;
avdtp_connection_t * btstack_memory_avdtp_connection_get(void){
    void * buffer = btstack_memory_pool_get(&avdtp_connection_pool);
    if (buffer){
        memset(buffer, 0, sizeof(avdtp_connection_t));
    }
    return (avdtp_connection_t *) buffer;
}
void btstack_memory_avdtp_connection_free(avdtp_connection_t *avdtp_connection){
    btstack_memory_pool_free(&avdtp_connection_pool, avdtp_connection);
}
#else
avdtp_connection_t * btstack_memory_avdtp_connection_get(void){
    return NULL;
}
void btstack_memory_avdtp_connection_free(avdtp_connection_t *avdtp_connection){
    // silence compiler warning about unused parameter in a portable way
    (void) avdtp_connection;
};
#endif
#elif defined(HAVE_MALLOC)
avdtp_connection_t * btstack_memory_avdtp_connection_get(void){
    void * buffer = malloc(sizeof(avdtp_connection_t));
    if (buffer){
        memset(buffer, 0, sizeof(avdtp_connection_t));
    }
    return (avdtp_connection_t *) buffer;
}
void btstack_memory_avdtp_connection_free(avdtp_connection_t *avdtp_connection){
    free(avdtp_connection);
}
#endif



// MARK: avrcp_connection_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_AVRCP_CONNECTIONS)
    #if defined(MAX_NO_AVRCP_CONNECTIONS)
        #error "Deprecated MAX_NO_AVRCP_CONNECTIONS defined instead of MAX_NR_AVRCP_CONNECTIONS. Please update your btstack_config.h to use MAX_NR_AVRCP_CONNECTIONS."
    #else
        #define MAX_NR_AVRCP_CONNECTIONS 0
    #endif
#endif

#ifdef MAX_NR_AVRCP_CONNECTIONS
#if MAX_NR_AVRCP_CONNECTIONS > 0
static avrcp_connection_t avrcp_connection_storage[MAX_NR_AVRCP_CONNECTIONS];
static btstack_memory_pool_t avrcp_connection_pool;
avrcp_connection_t * btstack_memory_avrcp_connection_get(void){
    void * buffer = btstack_memory_pool_get(&avrcp_connection_pool);
    if (buffer){
        memset(buffer, 0, sizeof(avrcp_connection_t));
    }
    return (avrcp_connection_t *) buffer;
}
void btstack_memory_avrcp_connection_free(avrcp_connection_t *avrcp_connection){
    btstack_memory_pool_free(&avrcp_connection_pool, avrcp_connection);
}
#else
avrcp_connection_t * btstack_memory_avrcp_connection_get(void){
    return NULL;
}
void btstack_memory_avrcp_connection_free(avrcp_connection_t *avrcp_connection){
    // silence compiler warning about unused parameter in a portable way
    (void) avrcp_connection;
};
#endif
#elif defined(HAVE_MALLOC)
avrcp_connection_t * btstack_memory_avrcp_connection_get(void){
    void * buffer = malloc(sizeof(avrcp_connection_t));
    if (buffer){
        memset(buffer, 0, sizeof(avrcp_connection_t));
    }
    return (avrcp_connection_t *) buffer;
}
void btstack_memory_avrcp_connection_free(avrcp_connection_t *avrcp_connection){
    free(avrcp_connection);
}
#endif



// MARK: avrcp_browsing_connection_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_AVRCP_BROWSING_CONNECTIONS)
    #if defined(MAX_NO_AVRCP_BROWSING_CONNECTIONS)
        #error "Deprecated MAX_NO_AVRCP_BROWSING_CONNECTIONS defined instead of MAX_NR_AVRCP_BROWSING_CONNECTIONS. Please update your btstack_config.h to use MAX_NR_AVRCP_BROWSING_CONNECTIONS."
    #else
        #define MAX_NR_AVRCP_BROWSING_CONNECTIONS 0
    #endif
#endif

#ifdef MAX_NR_AVRCP_BROWSING_CONNECTIONS
#if MAX_NR_AVRCP_BROWSING_CONNECTIONS > 0
static avrcp_browsing_connection_t avrcp_browsing_connection_storage[MAX_NR_AVRCP_BROWSING_CONNECTIONS];
static btstack_memory_pool_t avrcp_browsing_connection_pool;
avrcp_browsing_connection_t * btstack_memory_avrcp_browsing_connection_get(void){
    void * buffer = btstack_memory_pool_get(&avrcp_browsing_connection_pool);
    if (buffer){
        memset(buffer, 0, sizeof(avrcp_browsing_connection_t));
    }
    return (avrcp_browsing_connection_t *) buffer;
}
void btstack_memory_avrcp_browsing_connection_free(avrcp_browsing_connection_t *avrcp_browsing_connection){
    btstack_memory_pool_free(&avrcp_browsing_connection_pool, avrcp_browsing_connection);
}
#else
avrcp_browsing_connection_t * btstack_memory_avrcp_browsing_connection_get(void){
    return NULL;
}
void btstack_memory_avrcp_browsing_connection_free(avrcp_browsing_connection_t *avrcp_browsing_connection){
    // silence compiler warning about unused parameter in a portable way
    (void) avrcp_browsing_connection;
};
#endif
#elif defined(HAVE_MALLOC)
avrcp_browsing_connection_t * btstack_memory_avrcp_browsing_connection_get(void){
    void * buffer = malloc(sizeof(avrcp_browsing_connection_t));
    if (buffer){
        memset(buffer, 0, sizeof(avrcp_browsing_connection_t));
    }
    return (avrcp_browsing_connection_t *) buffer;
}
void btstack_memory_avrcp_browsing_connection_free(avrcp_browsing_connection_t *avrcp_browsing_connection){
    free(avrcp_browsing_connection);
}
#endif


#endif
#ifdef ENABLE_BLE

// MARK: gatt_client_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_GATT_CLIENTS)
    #if defined(MAX_NO_GATT_CLIENTS)
        #error "Deprecated MAX_NO_GATT_CLIENTS defined instead of MAX_NR_GATT_CLIENTS. Please update your btstack_config.h to use MAX_NR_GATT_CLIENTS."
    #else
        #define MAX_NR_GATT_CLIENTS 0
    #endif
#endif

#ifdef MAX_NR_GATT_CLIENTS
#if MAX_NR_GATT_CLIENTS > 0
static gatt_client_t gatt_client_storage[MAX_NR_GATT_CLIENTS];
static btstack_memory_pool_t gatt_client_pool;
gatt_client_t * btstack_memory_gatt_client_get(void){
    void * buffer = btstack_memory_pool_get(&gatt_client_pool);
    if (buffer){
        memset(buffer, 0, sizeof(gatt_client_t));
    }
    return (gatt_client_t *) buffer;
}
void btstack_memory_gatt_client_free(gatt_client_t *gatt_client){
    btstack_memory_pool_free(&gatt_client_pool, gatt_client);
}
#else
gatt_client_t * btstack_memory_gatt_client_get(void){
    return NULL;
}
void btstack_memory_gatt_client_free(gatt_client_t *gatt_client){
    // silence compiler warning about unused parameter in a portable way
    (void) gatt_client;
};
#endif
#elif defined(HAVE_MALLOC)
gatt_client_t * btstack_memory_gatt_client_get(void){
    void * buffer = malloc(sizeof(gatt_client_t));
    if (buffer){
        memset(buffer, 0, sizeof(gatt_client_t));
    }
    return (gatt_client_t *) buffer;
}
void btstack_memory_gatt_client_free(gatt_client_t *gatt_client){
    free(gatt_client);
}
#endif


// MARK: whitelist_entry_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_WHITELIST_ENTRIES)
    #if defined(MAX_NO_WHITELIST_ENTRIES)
        #error "Deprecated MAX_NO_WHITELIST_ENTRIES defined instead of MAX_NR_WHITELIST_ENTRIES. Please update your btstack_config.h to use MAX_NR_WHITELIST_ENTRIES."
    #else
        #define MAX_NR_WHITELIST_ENTRIES 0
    #endif
#endif

#ifdef MAX_NR_WHITELIST_ENTRIES
#if MAX_NR_WHITELIST_ENTRIES > 0
static whitelist_entry_t whitelist_entry_storage[MAX_NR_WHITELIST_ENTRIES];
static btstack_memory_pool_t whitelist_entry_pool;
whitelist_entry_t * btstack_memory_whitelist_entry_get(void){
    void * buffer = btstack_memory_pool_get(&whitelist_entry_pool);
    if (buffer){
        memset(buffer, 0, sizeof(whitelist_entry_t));
    }
    return (whitelist_entry_t *) buffer;
}
void btstack_memory_whitelist_entry_free(whitelist_entry_t *whitelist_entry){
    btstack_memory_pool_free(&whitelist_entry_pool, whitelist_entry);
}
#else
whitelist_entry_t * btstack_memory_whitelist_entry_get(void){
    return NULL;
}
void btstack_memory_whitelist_entry_free(whitelist_entry_t *whitelist_entry){
    // silence compiler warning about unused parameter in a portable way
    (void) whitelist_entry;
};
#endif
#elif defined(HAVE_MALLOC)
whitelist_entry_t * btstack_memory_whitelist_entry_get(void){
    void * buffer = malloc(sizeof(whitelist_entry_t));
    if (buffer){
        memset(buffer, 0, sizeof(whitelist_entry_t));
    }
    return (whitelist_entry_t *) buffer;
}
void btstack_memory_whitelist_entry_free(whitelist_entry_t *whitelist_entry){
    free(whitelist_entry);
}
#endif


// MARK: sm_lookup_entry_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_SM_LOOKUP_ENTRIES)
    #if defined(MAX_NO_SM_LOOKUP_ENTRIES)
        #error "Deprecated MAX_NO_SM_LOOKUP_ENTRIES defined instead of MAX_NR_SM_LOOKUP_ENTRIES. Please update your btstack_config.h to use MAX_NR_SM_LOOKUP_ENTRIES."
    #else
        #define MAX_NR_SM_LOOKUP_ENTRIES 0
    #endif
#endif

#ifdef MAX_NR_SM_LOOKUP_ENTRIES
#if MAX_NR_SM_LOOKUP_ENTRIES > 0
static sm_lookup_entry_t sm_lookup_entry_storage[MAX_NR_SM_LOOKUP_ENTRIES];
static btstack_memory_pool_t sm_lookup_entry_pool;
sm_lookup_entry_t * btstack_memory_sm_lookup_entry_get(void){
    void * buffer = btstack_memory_pool_get(&sm_lookup_entry_pool);
    if (buffer){
        memset(buffer, 0, sizeof(sm_lookup_entry_t));
    }
    return (sm_lookup_entry_t *) buffer;
}
void btstack_memory_sm_lookup_entry_free(sm_lookup_entry_t *sm_lookup_entry){
    btstack_memory_pool_free(&sm_lookup_entry_pool, sm_lookup_entry);
}
#else
sm_lookup_entry_t * btstack_memory_sm_lookup_entry_get(void){
    return NULL;
}
void btstack_memory_sm_lookup_entry_free(sm_lookup_entry_t *sm_lookup_entry){
    // silence compiler warning about unused parameter in a portable way
    (void) sm_lookup_entry;
};
#endif
#elif defined(HAVE_MALLOC)
sm_lookup_entry_t * btstack_memory_sm_lookup_entry_get(void){
    void * buffer = malloc(sizeof(sm_lookup_entry_t));
    if (buffer){
        memset(buffer, 0, sizeof(sm_lookup_entry_t));
    }
    return (sm_lookup_entry_t *) buffer;
}
void btstack_memory_sm_lookup_entry_free(sm_lookup_entry_t *sm_lookup_entry){
    free(sm_lookup_entry);
}
#endif


#endif
#ifdef ENABLE_MESH

// MARK: mesh_network_pdu_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_MESH_NETWORK_PDUS)
    #if defined(MAX_NO_MESH_NETWORK_PDUS)
        #error "Deprecated MAX_NO_MESH_NETWORK_PDUS defined instead of MAX_NR_MESH_NETWORK_PDUS. Please update your btstack_config.h to use MAX_NR_MESH_NETWORK_PDUS."
    #else
        #define MAX_NR_MESH_NETWORK_PDUS 0
    #endif
#endif

#ifdef MAX_NR_MESH_NETWORK_PDUS
#if MAX_NR_MESH_NETWORK_PDUS > 0
static mesh_network_pdu_t mesh_network_pdu_storage[MAX_NR_MESH_NETWORK_PDUS];
static btstack_memory_pool_t mesh_network_pdu_pool;
mesh_network_pdu_t * btstack_memory_mesh_network_pdu_get(void){
    return (mesh_network_pdu_t *) btstack_memory_pool_get(&mesh_network_pdu_pool);
}
void btstack_memory_mesh_network_pdu_free(mesh_network_pdu_t *mesh_network_pdu){
    btstack_memory_pool_free(&mesh_network_pdu_pool, mesh_network_pdu);
}
#else
mesh_network_pdu_t * btstack_memory_mesh_network_pdu_get(void){
    return NULL;
}
void btstack_memory_mesh_network_pdu_free(mesh_network_pdu_t *mesh_network_pdu){
    // silence compiler warning about unused parameter in a portable way
    (void) mesh_network_pdu;
};
#endif
#elif defined(HAVE_MALLOC)
mesh_network_pdu_t * btstack_memory_mesh_network_pdu_get(void){
    return (mesh_network_pdu_t*) malloc(sizeof(mesh_network_pdu_t));
}
void btstack_memory_mesh_network_pdu_free(mesh_network_pdu_t *mesh_network_pdu){
    free(mesh_network_pdu);
}
#endif


// MARK: mesh_transport_pdu_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_MESH_TRANSPORT_PDUS)
    #if defined(MAX_NO_MESH_TRANSPORT_PDUS)
        #error "Deprecated MAX_NO_MESH_TRANSPORT_PDUS defined instead of MAX_NR_MESH_TRANSPORT_PDUS. Please update your btstack_config.h to use MAX_NR_MESH_TRANSPORT_PDUS."
    #else
        #define MAX_NR_MESH_TRANSPORT_PDUS 0
    #endif
#endif

#ifdef MAX_NR_MESH_TRANSPORT_PDUS
#if MAX_NR_MESH_TRANSPORT_PDUS > 0
static mesh_transport_pdu_t mesh_transport_pdu_storage[MAX_NR_MESH_TRANSPORT_PDUS];
static btstack_memory_pool_t mesh_transport_pdu_pool;
mesh_transport_pdu_t * btstack_memory_mesh_transport_pdu_get(void){
    return (mesh_transport_pdu_t *) btstack_memory_pool_get(&mesh_transport_pdu_pool);
}
void btstack_memory_mesh_transport_pdu_free(mesh_transport_pdu_t *mesh_transport_pdu){
    btstack_memory_pool_free(&mesh_transport_pdu_pool, mesh_transport_pdu);
}
#else
mesh_transport_pdu_t * btstack_memory_mesh_transport_pdu_get(void){
    return NULL;
}
void btstack_memory_mesh_transport_pdu_free(mesh_transport_pdu_t *mesh_transport_pdu){
    // silence compiler warning about unused parameter in a portable way
    (void) mesh_transport_pdu;
};
#endif
#elif defined(HAVE_MALLOC)
mesh_transport_pdu_t * btstack_memory_mesh_transport_pdu_get(void){
    return (mesh_transport_pdu_t*) malloc(sizeof(mesh_transport_pdu_t));
}
void btstack_memory_mesh_transport_pdu_free(mesh_transport_pdu_t *mesh_transport_pdu){
    free(mesh_transport_pdu);
}
#endif


// MARK: mesh_network_key_t
#if !defined(HAVE_MALLOC) && !defined(MAX_NR_MESH_NETWORK_KEYS)
    #if defined(MAX_NO_MESH_NETWORK_KEYS)
        #error "Deprecated MAX_NO_MESH_NETWORK_KEYS defined instead of MAX_NR_MESH_NETWORK_KEYS. Please update your btstack_config.h to use MAX_NR_MESH_NETWORK_KEYS."
    #else
        #define MAX_NR_MESH_NETWORK_KEYS 0
    #endif
#endif

#ifdef MAX_NR_MESH_NETWORK_KEYS
#if MAX_NR_MESH_NETWORK_KEYS > 0
static mesh_network_key_t mesh_network_key_storage[MAX_NR_MESH_NETWORK_KEYS];
static btstack_memory_pool_t mesh_network_key_pool;
mesh_network_key_t * btstack_memory_mesh_network_key_get(void){
    return (mesh_network_key_t *) btstack_memory_pool_get(&mesh_network_key_pool);
}
void btstack_memory_mesh_network_key_free(mesh_network_key_t *mesh_network_key){
    btstack_memory_pool_free(&mesh_network_key_pool, mesh_network_key);
}
#else
mesh_network_key_t * btstack_memory_mesh_network_key_get(void){
    return NULL;
}
void btstack_memory_mesh_network_key_free(mesh_network_key_t *mesh_network_key){
    // silence compiler warning about unused parameter in a portable way
    (void) mesh_network_key;
};
#endif
#elif defined(HAVE_MALLOC)
mesh_network_key_t * btstack_memory_mesh_network_key_get(void){
    return (mesh_network_key_t*) malloc(sizeof(mesh_network_key_t));
}
void btstack_memory_mesh_network_key_free(mesh_network_key_t *mesh_network_key){
    free(mesh_network_key);
}
#endif


#endif
// init
void btstack_memory_init(void){
#if MAX_NR_HCI_CONNECTIONS > 0
    btstack_memory_pool_create(&hci_connection_pool, hci_connection_storage, MAX_NR_HCI_CONNECTIONS, sizeof(hci_connection_t));
#endif
#if MAX_NR_L2CAP_SERVICES > 0
    btstack_memory_pool_create(&l2cap_service_pool, l2cap_service_storage, MAX_NR_L2CAP_SERVICES, sizeof(l2cap_service_t));
#endif
#if MAX_NR_L2CAP_CHANNELS > 0
    btstack_memory_pool_create(&l2cap_channel_pool, l2cap_channel_storage, MAX_NR_L2CAP_CHANNELS, sizeof(l2cap_channel_t));
#endif
#ifdef ENABLE_CLASSIC
#if MAX_NR_GATT_CLIENTS > 0
    btstack_memory_pool_create(&gatt_client_pool, gatt_client_storage, MAX_NR_GATT_CLIENTS, sizeof(gatt_client_t));
#endif
#if MAX_NR_WHITELIST_ENTRIES > 0
    btstack_memory_pool_create(&whitelist_entry_pool, whitelist_entry_storage, MAX_NR_WHITELIST_ENTRIES, sizeof(whitelist_entry_t));
#endif
#if MAX_NR_SM_LOOKUP_ENTRIES > 0
    btstack_memory_pool_create(&sm_lookup_entry_pool, sm_lookup_entry_storage, MAX_NR_SM_LOOKUP_ENTRIES, sizeof(sm_lookup_entry_t));
#endif
#endif
#ifdef ENABLE_BLE
#if MAX_NR_GATT_CLIENTS > 0
    btstack_memory_pool_create(&gatt_client_pool, gatt_client_storage, MAX_NR_GATT_CLIENTS, sizeof(gatt_client_t));
#endif
#if MAX_NR_WHITELIST_ENTRIES > 0
    btstack_memory_pool_create(&whitelist_entry_pool, whitelist_entry_storage, MAX_NR_WHITELIST_ENTRIES, sizeof(whitelist_entry_t));
#endif
#if MAX_NR_SM_LOOKUP_ENTRIES > 0
    btstack_memory_pool_create(&sm_lookup_entry_pool, sm_lookup_entry_storage, MAX_NR_SM_LOOKUP_ENTRIES, sizeof(sm_lookup_entry_t));
#endif
#endif
#ifdef ENABLE_MESH
#if MAX_NR_GATT_CLIENTS > 0
    btstack_memory_pool_create(&gatt_client_pool, gatt_client_storage, MAX_NR_GATT_CLIENTS, sizeof(gatt_client_t));
#endif
#if MAX_NR_WHITELIST_ENTRIES > 0
    btstack_memory_pool_create(&whitelist_entry_pool, whitelist_entry_storage, MAX_NR_WHITELIST_ENTRIES, sizeof(whitelist_entry_t));
#endif
#if MAX_NR_SM_LOOKUP_ENTRIES > 0
    btstack_memory_pool_create(&sm_lookup_entry_pool, sm_lookup_entry_storage, MAX_NR_SM_LOOKUP_ENTRIES, sizeof(sm_lookup_entry_t));
#endif
#endif
}
