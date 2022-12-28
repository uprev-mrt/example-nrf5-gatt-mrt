/**
 * @file example_svc.h
 * @brief GATT profile example
 * @date 12/27/22
 * 
 */

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "svc/dvc_svc.h"
#include "svc/bat_svc.h"
#include "svc/spr_svc.h"
#include "svc/ota_svc.h"

/*user-block-top-start*/
/*user-block-top-end*/
/* Exported Macros ------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

typedef struct{
    mrt_gatt_pro_t mPro;
    dvc_svc_t* mDevice;                          /* The Device Information Service exposes manufacturer    and/or vendor information about a device. */
    bat_svc_t* mBattery;                         /* The Battery Service exposes the state of a battery    within a device. */
    spr_svc_t* mSprinkler;                       /* Custom service for a sprinkler system */
    ota_svc_t* mFota;                            /* sercive for performing over the air updates */
}example_profile_t;

/* Exported constants --------------------------------------------------------*/
extern example_profile_t example_profile;
/* Exported functions ------------------------------------------------------- */

/**
 * @brief initialize profile
 * @param ctx ptr to context (defined by platform)
 */
mrt_status_t example_profile_init(void* ctx);

mrt_status_t example_profile_register(void);

/*user-block-functions-start*/
/*user-block-functions-end*/

#ifdef __cplusplus
}
#endif