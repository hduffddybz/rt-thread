/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2009 - 2011, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2011-05-24     Bernard      the first version
 */

/**
 * @addtogroup FM3
 */
/*@{*/

#include <rtthread.h>
#include <rtdevice.h>
#include "board.h"

#ifdef  RT_USING_COMPONENTS_INIT
#include <components.h>
#endif  /* RT_USING_COMPONENTS_INIT */
#ifdef RT_USING_FINSH
#include <finsh.h> 
#endif

void rt_init_thread_entry(void *parameter)
{
#ifdef RT_USING_COMPONENTS_INIT
    /* initialization RT-Thread Components */
    rt_components_init();
#endif

#ifdef  RT_USING_FINSH
    finsh_system_init();
#endif  /* RT_USING_FINSH */
}

int rt_application_init()
{
    rt_thread_t tid;

    tid = rt_thread_create("init",
                           rt_init_thread_entry, RT_NULL,
                           2048, 8, 20);
    if (tid != RT_NULL) rt_thread_startup(tid);

    return 0;
}

/*@}*/
