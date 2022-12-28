/**
 * @file example_profile.h
 * @brief GATT profile example
 * @date 12/27/22
 * 
 */

/* Includes ------------------------------------------------------------------*/
#include "example_profile.h"


/*user-block-top-start*/
/*user-block-top-end*/

/* Private Variables ---------------------------------------------------------*/
MRT_GATT_DATA_ATTR example_profile_t example_profile;


/* Functions -----------------------------------------------------------------*/

mrt_status_t example_profile_init(void* ctx)
{
    mrt_gatt_init_pro(&example_profile.mPro, 4, 0, "example");

    //Set Context Pointer
    example_profile.mPro.ctx = ctx;
    
    /* Initialize all services */
    example_profile.mDevice = dvc_svc_init(&example_profile.mPro);
    example_profile.mBattery = bat_svc_init(&example_profile.mPro);
    example_profile.mSprinkler = spr_svc_init(&example_profile.mPro);
    example_profile.mFota = ota_svc_init(&example_profile.mPro);

    /*user-block-init-start*/
    /*user-block-init-end*/
    
    return MRT_STATUS_OK;
}

mrt_status_t example_profile_register(void)
{
    mrt_status_t status;



    for(uint16_t i =0; i < example_profile.mPro.svcCount; i++ )
    {
        status = mrt_gatt_register_svc(example_profile.mPro.svcs[i]);
        if(status != MRT_STATUS_OK)
        {
            break;
        }

    }

    /*user-block-register-start*/
    /*user-block-register-end*/

    return status;
}



/*user-block-functions-start*/
/*user-block-functions-end*/
