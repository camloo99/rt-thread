/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-11-09     shelton      first version
 */

#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__

#include <rtthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UART1_IRQHandler      USART1_IRQHandler
#define UART2_IRQHandler      USART2_IRQHandler
#define UART3_IRQHandler      USART4_3_IRQHandler
#define UART4_IRQHandler      USART4_3_IRQHandler

#if defined(BSP_USING_UART1)
#define UART1_CONFIG                                                \
    {                                                               \
        .name = "uart1",                                            \
        .uart_x = USART1,                                           \
        .irqn = USART1_IRQn,                                        \
    }
#endif /* BSP_USING_UART1 */

#if defined(BSP_USING_UART2)
#define UART2_CONFIG                                                \
    {                                                               \
        .name = "uart2",                                            \
        .uart_x = USART2,                                           \
        .irqn = USART2_IRQn,                                        \
    }
#endif /* BSP_USING_UART2 */

#if defined(BSP_USING_UART3)
#define UART3_CONFIG                                                \
    {                                                               \
        .name = "uart3",                                            \
        .uart_x = USART3,                                           \
        .irqn = USART3_IRQn,                                        \
    }
#endif /* BSP_USING_UART3 */

#if defined(BSP_USING_UART4)
#define UART4_CONFIG                                                \
    {                                                               \
        .name = "uart4",                                            \
        .uart_x = USART4,                                           \
        .irqn = USART4_IRQn,                                        \
    }
#endif /* BSP_USING_UART4 */

#ifdef __cplusplus
}
#endif

#endif
