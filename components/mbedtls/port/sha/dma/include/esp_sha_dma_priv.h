// Copyright 2020 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "soc/lldesc.h"
#include "soc/soc_caps.h"
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

#if SOC_SHA_GDMA

/**
 * @brief Initialize the GDMA channel
 *
 * @note Allocate and initialize a DMA channel (tx) for the SHA peripheral
 *       Only one channel will be initialized at any given time. If two or more SHA operations are
 *       run in parallel the channel will be shared sequentially.
 *
 */
void esp_sha_dma_init(void);

/**
 * @brief Free the GDMA channel
 *
 * @note The channel will only be freed if there are no other SHA operations currently using it
 *
 */
void esp_sha_dma_free(void);
#endif //SOC_SHA_GDMA

/**
 * @brief Start the DMA engine
 *
 * @param input SHA input descriptor (outlink)
 * @return
 *      - ESP_OK: Successfully started the DMA
 *      - ESP_ERR_INVALID_STATE: No DMA channel available
 */
esp_err_t esp_sha_dma_start(const lldesc_t *input);


#ifdef __cplusplus
}
#endif
