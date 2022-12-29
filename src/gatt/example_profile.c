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

    /* Call post-registration handlers */
    dvc_svc_post_registration_handler();
    bat_svc_post_registration_handler();
    spr_svc_post_registration_handler();
    ota_svc_post_registration_handler();

    /*user-block-register-start*/
    /*user-block-register-end*/

    return status;
}

mrt_status_t example_profile_handle_evt(mrt_gatt_evt_t* evt)
{


    if(evt->chr == NULL)
    {
        return MRT_STATUS_OK;
    }

    //If it is a CCCD write, update the CCCD fpr the characteristic
    if((evt->type == MRT_GATT_EVT_CCCD_WRITE) )
    {
        evt->chr->cccd = *((uint16_t*)evt->data.value);
    }

    /**
     * ** BY DEFAULT WE ONLY PASS WRITE EVENTS TO THE CHARACTERISTIC CALLBACK HANDLERS **
     * To pass all events to the handler, comment out the following line
     */
    if(evt->type != MRT_GATT_EVT_VALUE_WRITE){return MRT_STATUS_OK;}

    
    //By default only call the event callback for write events because READ events are auto-response by default
    if((evt->chr != NULL) && (evt->type != MRT_GATT_EVT_NONE))
    {
        //ESP_LOGE(GATT_ADAPTER_TAG, "CALLBACK  Event Type: %04X", evt->type );
        evt->status = evt->chr->cbEvent(evt);
    }

    /*user-block-profile-handler-start*/
    /*user-block-profile-handler-end*/



    return MRT_STATUS_OK;
}



/*user-block-functions-start*/
/*user-block-functions-end*/
