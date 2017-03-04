/********************************************\
 *              DEFINES.H                   *
 * Universal defines for STM32F030XXXX MCUs *
 *  Written by Yaroslav Zaruchevskiy, 2016  *
 *        zaruchevskiy@yarzar.ru            *
\********************************************/
#ifndef DEFINES_H
#define DEFINES_H

// SECTION: SETTINGS \\

#ifndef STM32F030x6
//#error "Defines are written for STM32F030, an error may occur!"
#endif
#define CPU_CLOCK ((uint32_t)48000000)
#define nop() asm("NOP");

// SECTION: TYPEDEFS \\

typedef volatile uint8_t vuint8_t ;

// SECTION: GPIO \\

/* GPIO_MODER */
#define GPIO_MODER_0_OUT ((uint32_t)0x00000001)
#define GPIO_MODER_0_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_0_AF  ((uint32_t)0x00000002)
#define GPIO_MODER_0_ADC ((uint32_t)0x00000003)

#define GPIO_MODER_1_OUT ((uint32_t)0x00000004)
#define GPIO_MODER_1_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_1_AF  ((uint32_t)0x00000008)
#define GPIO_MODER_1_ADC ((uint32_t)0x0000000C)

#define GPIO_MODER_2_OUT ((uint32_t)0x00000010)
#define GPIO_MODER_2_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_2_AF  ((uint32_t)0x00000020)
#define GPIO_MODER_2_ADC ((uint32_t)0x00000030)

#define GPIO_MODER_3_OUT ((uint32_t)0x00000040)
#define GPIO_MODER_3_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_3_AF  ((uint32_t)0x00000080)
#define GPIO_MODER_3_ADC ((uint32_t)0x000000C0)

#define GPIO_MODER_4_OUT ((uint32_t)0x00000100)
#define GPIO_MODER_4_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_4_AF  ((uint32_t)0x00000200)
#define GPIO_MODER_4_ADC ((uint32_t)0x00000300)

#define GPIO_MODER_5_OUT ((uint32_t)0x00000400)
#define GPIO_MODER_5_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_5_AF  ((uint32_t)0x00000800)
#define GPIO_MODER_5_ADC ((uint32_t)0x00000C00)

#define GPIO_MODER_6_OUT ((uint32_t)0x00001000)
#define GPIO_MODER_6_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_6_AF  ((uint32_t)0x00002000)
#define GPIO_MODER_6_ADC ((uint32_t)0x00003000)

#define GPIO_MODER_7_OUT ((uint32_t)0x00004000)
#define GPIO_MODER_7_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_7_AF  ((uint32_t)0x00008000)
#define GPIO_MODER_7_ADC ((uint32_t)0x0000C000)

#define GPIO_MODER_8_OUT ((uint32_t)0x00010000)
#define GPIO_MODER_8_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_8_AF  ((uint32_t)0x00020000)
#define GPIO_MODER_8_ADC ((uint32_t)0x00030000)

#define GPIO_MODER_9_OUT ((uint32_t)0x00040000)
#define GPIO_MODER_9_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_9_AF  ((uint32_t)0x00080000)
#define GPIO_MODER_9_ADC ((uint32_t)0x000C0000)

#define GPIO_MODER_10_OUT ((uint32_t)0x00100000)
#define GPIO_MODER_10_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_10_AF  ((uint32_t)0x00200000)
#define GPIO_MODER_10_ADC ((uint32_t)0x00300000)

#define GPIO_MODER_11_OUT ((uint32_t)0x00400000)
#define GPIO_MODER_11_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_11_AF  ((uint32_t)0x00800000)
#define GPIO_MODER_11_ADC ((uint32_t)0x00C00000)

#define GPIO_MODER_12_OUT ((uint32_t)0x01000000)
#define GPIO_MODER_12_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_12_AF  ((uint32_t)0x02000000)
#define GPIO_MODER_12_ADC ((uint32_t)0x03000000)

#define GPIO_MODER_13_OUT ((uint32_t)0x04000000)
#define GPIO_MODER_13_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_13_AF  ((uint32_t)0x08000000)
#define GPIO_MODER_13_ADC ((uint32_t)0x0C000000)

#define GPIO_MODER_14_OUT ((uint32_t)0x10000000)
#define GPIO_MODER_14_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_14_AF  ((uint32_t)0x20000000)
#define GPIO_MODER_14_ADC ((uint32_t)0x30000000)

#define GPIO_MODER_15_OUT ((uint32_t)0x40000000)
#define GPIO_MODER_15_IN  ((uint32_t)0x00000000)
#define GPIO_MODER_15_AF  ((uint32_t)0x80000000)
#define GPIO_MODER_15_ADC ((uint32_t)0xC0000000)


/* GPIO_OTYPER */
#define GPIO_OTYPER_0_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_0_OD  ((uint32_t)0x00000001)

#define GPIO_OTYPER_1_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_1_OD  ((uint32_t)0x00000002)

#define GPIO_OTYPER_2_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_2_OD  ((uint32_t)0x00000004)

#define GPIO_OTYPER_3_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_3_OD  ((uint32_t)0x00000008)

#define GPIO_OTYPER_4_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_4_OD  ((uint32_t)0x00000010)

#define GPIO_OTYPER_5_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_5_OD  ((uint32_t)0x00000020)

#define GPIO_OTYPER_6_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_6_OD  ((uint32_t)0x00000040)

#define GPIO_OTYPER_7_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_7_OD  ((uint32_t)0x00000080)

#define GPIO_OTYPER_8_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_8_OD  ((uint32_t)0x00000100)

#define GPIO_OTYPER_9_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_9_OD  ((uint32_t)0x00000200)

#define GPIO_OTYPER_10_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_10_OD  ((uint32_t)0x00000400)

#define GPIO_OTYPER_11_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_11_OD  ((uint32_t)0x00000800)

#define GPIO_OTYPER_12_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_12_OD  ((uint32_t)0x00001000)

#define GPIO_OTYPER_13_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_13_OD  ((uint32_t)0x00002000)

#define GPIO_OTYPER_14_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_14_OD  ((uint32_t)0x00004000)

#define GPIO_OTYPER_15_PP  ((uint32_t)0x00000000)
#define GPIO_OTYPER_15_OD  ((uint32_t)0x00008000)

/* GPIO_OSPEEDR */
#define GPIO_OSPEEDR_0_LOW  ((uint32_t)0x00000002)
#define GPIO_OSPEEDR_0_MED  ((uint32_t)0x00000001)
#define GPIO_OSPEEDR_0_FAS  ((uint32_t)0x00000003)

#define GPIO_OSPEEDR_1_LOW  ((uint32_t)0x00000008)
#define GPIO_OSPEEDR_1_MED  ((uint32_t)0x00000004)
#define GPIO_OSPEEDR_1_FAS  ((uint32_t)0x0000000C)

#define GPIO_OSPEEDR_2_LOW  ((uint32_t)0x00000020)
#define GPIO_OSPEEDR_2_MED  ((uint32_t)0x00000010)
#define GPIO_OSPEEDR_2_FAS  ((uint32_t)0x000000C0)

#define GPIO_OSPEEDR_3_LOW  ((uint32_t)0x00000080)
#define GPIO_OSPEEDR_3_MED  ((uint32_t)0x00000040)
#define GPIO_OSPEEDR_3_FAS  ((uint32_t)0x000000C0)

#define GPIO_OSPEEDR_4_LOW  ((uint32_t)0x00000200)
#define GPIO_OSPEEDR_4_MED  ((uint32_t)0x00000100)
#define GPIO_OSPEEDR_4_FAS  ((uint32_t)0x00000C00)

#define GPIO_OSPEEDR_5_LOW  ((uint32_t)0x00000800)
#define GPIO_OSPEEDR_5_MED  ((uint32_t)0x00000400)
#define GPIO_OSPEEDR_5_FAS  ((uint32_t)0x00000C00)

#define GPIO_OSPEEDR_6_LOW  ((uint32_t)0x00002000)
#define GPIO_OSPEEDR_6_MED  ((uint32_t)0x00001000)
#define GPIO_OSPEEDR_6_FAS  ((uint32_t)0x00003000)

#define GPIO_OSPEEDR_7_LOW  ((uint32_t)0x00008000)
#define GPIO_OSPEEDR_7_MED  ((uint32_t)0x00004000)
#define GPIO_OSPEEDR_7_FAS  ((uint32_t)0x0000C000)

#define GPIO_OSPEEDR_8_LOW  ((uint32_t)0x00020000)
#define GPIO_OSPEEDR_8_MED  ((uint32_t)0x00010000)
#define GPIO_OSPEEDR_8_FAS  ((uint32_t)0x00030000)

#define GPIO_OSPEEDR_9_LOW  ((uint32_t)0x00080000)
#define GPIO_OSPEEDR_9_MED  ((uint32_t)0x00040000)
#define GPIO_OSPEEDR_9_FAS  ((uint32_t)0x000C0000)

#define GPIO_OSPEEDR_10_LOW  ((uint32_t)0x00200000)
#define GPIO_OSPEEDR_10_MED  ((uint32_t)0x00100000)
#define GPIO_OSPEEDR_10_FAS  ((uint32_t)0x00300000)

#define GPIO_OSPEEDR_11_LOW  ((uint32_t)0x00800000)
#define GPIO_OSPEEDR_11_MED  ((uint32_t)0x00400000)
#define GPIO_OSPEEDR_11_FAS  ((uint32_t)0x00C00000)

#define GPIO_OSPEEDR_12_LOW  ((uint32_t)0x02000000)
#define GPIO_OSPEEDR_12_MED  ((uint32_t)0x01000000)
#define GPIO_OSPEEDR_12_FAS  ((uint32_t)0x03000000)

#define GPIO_OSPEEDR_13_LOW  ((uint32_t)0x08000000)
#define GPIO_OSPEEDR_13_MED  ((uint32_t)0x04000000)
#define GPIO_OSPEEDR_13_FAS  ((uint32_t)0x0C000000)

#define GPIO_OSPEEDR_14_LOW  ((uint32_t)0x20000000)
#define GPIO_OSPEEDR_14_MED  ((uint32_t)0x10000000)
#define GPIO_OSPEEDR_14_FAS  ((uint32_t)0x30000000)

#define GPIO_OSPEEDR_15_LOW  ((uint32_t)0x80000000)
#define GPIO_OSPEEDR_15_MED  ((uint32_t)0x40000000)
#define GPIO_OSPEEDR_15_FAS  ((uint32_t)0xC0000000)


/* GPIO_PUPDR */
#define GPIO_PUPDR_0_UP ((uint32_t)0x00000001)
#define GPIO_PUPDR_0_DN ((uint32_t)0x00000002)
#define GPIO_PUPDR_0_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_1_UP ((uint32_t)0x00000004)
#define GPIO_PUPDR_1_DN ((uint32_t)0x00000008)
#define GPIO_PUPDR_1_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_2_UP ((uint32_t)0x00000010)
#define GPIO_PUPDR_2_DN ((uint32_t)0x00000020)
#define GPIO_PUPDR_2_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_3_UP ((uint32_t)0x00000040)
#define GPIO_PUPDR_3_DN ((uint32_t)0x00000080)
#define GPIO_PUPDR_3_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_4_UP ((uint32_t)0x00000100)
#define GPIO_PUPDR_4_DN ((uint32_t)0x00000200)
#define GPIO_PUPDR_4_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_5_UP ((uint32_t)0x00000400)
#define GPIO_PUPDR_5_DN ((uint32_t)0x00000800)
#define GPIO_PUPDR_5_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_6_UP ((uint32_t)0x00001000)
#define GPIO_PUPDR_6_DN ((uint32_t)0x00002000)
#define GPIO_PUPDR_6_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_7_UP ((uint32_t)0x00004000)
#define GPIO_PUPDR_7_DN ((uint32_t)0x00008000)
#define GPIO_PUPDR_7_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_8_UP ((uint32_t)0x00010000)
#define GPIO_PUPDR_8_DN ((uint32_t)0x00020000)
#define GPIO_PUPDR_8_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_9_UP ((uint32_t)0x00040000)
#define GPIO_PUPDR_9_DN ((uint32_t)0x00080000)
#define GPIO_PUPDR_9_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_10_UP ((uint32_t)0x00100000)
#define GPIO_PUPDR_10_DN ((uint32_t)0x00200000)
#define GPIO_PUPDR_10_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_11_UP ((uint32_t)0x00400000)
#define GPIO_PUPDR_11_DN ((uint32_t)0x00800000)
#define GPIO_PUPDR_11_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_12_UP ((uint32_t)0x01000000)
#define GPIO_PUPDR_12_DN ((uint32_t)0x02000000)
#define GPIO_PUPDR_12_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_13_UP ((uint32_t)0x04000000)
#define GPIO_PUPDR_13_DN ((uint32_t)0x08000000)
#define GPIO_PUPDR_13_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_14_UP ((uint32_t)0x10000000)
#define GPIO_PUPDR_14_DN ((uint32_t)0x20000000)
#define GPIO_PUPDR_14_NO ((uint32_t)0x00000000)

#define GPIO_PUPDR_15_UP ((uint32_t)0x40000000)
#define GPIO_PUPDR_15_DN ((uint32_t)0x80000000)
#define GPIO_PUPDR_15_NO ((uint32_t)0x00000000)

/* GPIO_BSRR */
#define GPIO_BSRR_0_S  ((uint32_t)0x00000001)
#define GPIO_BSRR_0_R  ((uint32_t)0x00010000)

#define GPIO_BSRR_1_S  ((uint32_t)0x00000002)
#define GPIO_BSRR_1_R  ((uint32_t)0x00020000)

#define GPIO_BSRR_2_S  ((uint32_t)0x00000004)
#define GPIO_BSRR_2_R  ((uint32_t)0x00040000)

#define GPIO_BSRR_3_S  ((uint32_t)0x00000008)
#define GPIO_BSRR_3_R  ((uint32_t)0x00080000)

#define GPIO_BSRR_4_S  ((uint32_t)0x00000010)
#define GPIO_BSRR_4_R  ((uint32_t)0x00100000)

#define GPIO_BSRR_5_S  ((uint32_t)0x00000020)
#define GPIO_BSRR_5_R  ((uint32_t)0x00200000)

#define GPIO_BSRR_6_S  ((uint32_t)0x00000040)
#define GPIO_BSRR_6_R  ((uint32_t)0x00400000)

#define GPIO_BSRR_7_S  ((uint32_t)0x00000080)
#define GPIO_BSRR_7_R  ((uint32_t)0x00800000)

#define GPIO_BSRR_8_S  ((uint32_t)0x00000100)
#define GPIO_BSRR_8_R  ((uint32_t)0x01000000)

#define GPIO_BSRR_9_S  ((uint32_t)0x00000200)
#define GPIO_BSRR_9_R  ((uint32_t)0x02000000)

#define GPIO_BSRR_10_S  ((uint32_t)0x00000400)
#define GPIO_BSRR_10_R  ((uint32_t)0x04000000)

#define GPIO_BSRR_11_S  ((uint32_t)0x00000800)
#define GPIO_BSRR_11_R  ((uint32_t)0x08000000)

#define GPIO_BSRR_12_S  ((uint32_t)0x00001000)
#define GPIO_BSRR_12_R  ((uint32_t)0x10000000)

#define GPIO_BSRR_13_S  ((uint32_t)0x00002000)
#define GPIO_BSRR_13_R  ((uint32_t)0x20000000)

#define GPIO_BSRR_14_S  ((uint32_t)0x00004000)
#define GPIO_BSRR_14_R  ((uint32_t)0x40000000)

#define GPIO_BSRR_15_S  ((uint32_t)0x00008000)
#define GPIO_BSRR_15_R  ((uint32_t)0x80000000)

/* GPIOx_AFRL */
#define GPIO_AFRL_0_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_0_A1  ((uint32_t)0x00000001)
#define GPIO_AFRL_0_A2  ((uint32_t)0x00000002)
#define GPIO_AFRL_0_A3  ((uint32_t)0x00000003)
#define GPIO_AFRL_0_A4  ((uint32_t)0x00000004)
#define GPIO_AFRL_0_A5  ((uint32_t)0x00000005)
#define GPIO_AFRL_0_A6  ((uint32_t)0x00000006)
#define GPIO_AFRL_0_A7  ((uint32_t)0x00000007)

#define GPIO_AFRL_1_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_1_A1  ((uint32_t)0x00000010)
#define GPIO_AFRL_1_A2  ((uint32_t)0x00000020)
#define GPIO_AFRL_1_A3  ((uint32_t)0x00000030)
#define GPIO_AFRL_1_A4  ((uint32_t)0x00000040)
#define GPIO_AFRL_1_A5  ((uint32_t)0x00000050)
#define GPIO_AFRL_1_A6  ((uint32_t)0x00000060)
#define GPIO_AFRL_1_A7  ((uint32_t)0x00000070)

#define GPIO_AFRL_2_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_2_A1  ((uint32_t)0x00000100)
#define GPIO_AFRL_2_A2  ((uint32_t)0x00000200)
#define GPIO_AFRL_2_A3  ((uint32_t)0x00000300)
#define GPIO_AFRL_2_A4  ((uint32_t)0x00000400)
#define GPIO_AFRL_2_A5  ((uint32_t)0x00000500)
#define GPIO_AFRL_2_A6  ((uint32_t)0x00000600)
#define GPIO_AFRL_2_A7  ((uint32_t)0x00000700)

#define GPIO_AFRL_3_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_3_A1  ((uint32_t)0x00001000)
#define GPIO_AFRL_3_A2  ((uint32_t)0x00002000)
#define GPIO_AFRL_3_A3  ((uint32_t)0x00003000)
#define GPIO_AFRL_3_A4  ((uint32_t)0x00004000)
#define GPIO_AFRL_3_A5  ((uint32_t)0x00005000)
#define GPIO_AFRL_3_A6  ((uint32_t)0x00006000)
#define GPIO_AFRL_3_A7  ((uint32_t)0x00007000)

#define GPIO_AFRL_4_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_4_A1  ((uint32_t)0x00010000)
#define GPIO_AFRL_4_A2  ((uint32_t)0x00020000)
#define GPIO_AFRL_4_A3  ((uint32_t)0x00030000)
#define GPIO_AFRL_4_A4  ((uint32_t)0x00040000)
#define GPIO_AFRL_4_A5  ((uint32_t)0x00050000)
#define GPIO_AFRL_4_A6  ((uint32_t)0x00060000)
#define GPIO_AFRL_4_A7  ((uint32_t)0x00070000)

#define GPIO_AFRL_5_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_5_A1  ((uint32_t)0x00100000)
#define GPIO_AFRL_5_A2  ((uint32_t)0x00200000)
#define GPIO_AFRL_5_A3  ((uint32_t)0x00300000)
#define GPIO_AFRL_5_A4  ((uint32_t)0x00400000)
#define GPIO_AFRL_5_A5  ((uint32_t)0x00500000)
#define GPIO_AFRL_5_A6  ((uint32_t)0x00600000)
#define GPIO_AFRL_5_A7  ((uint32_t)0x00700000)

#define GPIO_AFRL_6_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_6_A1  ((uint32_t)0x01000000)
#define GPIO_AFRL_6_A2  ((uint32_t)0x02000000)
#define GPIO_AFRL_6_A3  ((uint32_t)0x03000000)
#define GPIO_AFRL_6_A4  ((uint32_t)0x04000000)
#define GPIO_AFRL_6_A5  ((uint32_t)0x05000000)
#define GPIO_AFRL_6_A6  ((uint32_t)0x06000000)
#define GPIO_AFRL_6_A7  ((uint32_t)0x07000000)

#define GPIO_AFRL_7_A0  ((uint32_t)0x00000000)
#define GPIO_AFRL_7_A1  ((uint32_t)0x10000000)
#define GPIO_AFRL_7_A2  ((uint32_t)0x20000000)
#define GPIO_AFRL_7_A3  ((uint32_t)0x30000000)
#define GPIO_AFRL_7_A4  ((uint32_t)0x40000000)
#define GPIO_AFRL_7_A5  ((uint32_t)0x50000000)
#define GPIO_AFRL_7_A6  ((uint32_t)0x60000000)
#define GPIO_AFRL_7_A7  ((uint32_t)0x70000000)

/* GPIOx_AFRH */
#define GPIO_AFRH_8_A0  ((uint32_t)0x00000000)
#define GPIO_AFRH_8_A1  ((uint32_t)0x00000001)
#define GPIO_AFRH_8_A2  ((uint32_t)0x00000002)
#define GPIO_AFRH_8_A3  ((uint32_t)0x00000003)
#define GPIO_AFRH_8_A4  ((uint32_t)0x00000004)
#define GPIO_AFRH_8_A5  ((uint32_t)0x00000005)
#define GPIO_AFRH_8_A6  ((uint32_t)0x00000006)
#define GPIO_AFRH_8_A7  ((uint32_t)0x00000007)

#define GPIO_AFRH_9_A0  ((uint32_t)0x00000000)
#define GPIO_AFRH_9_A1  ((uint32_t)0x00000010)
#define GPIO_AFRH_9_A2  ((uint32_t)0x00000020)
#define GPIO_AFRH_9_A3  ((uint32_t)0x00000030)
#define GPIO_AFRH_9_A4  ((uint32_t)0x00000040)
#define GPIO_AFRH_9_A5  ((uint32_t)0x00000050)
#define GPIO_AFRH_9_A6  ((uint32_t)0x00000060)
#define GPIO_AFRH_9_A7  ((uint32_t)0x00000070)

#define GPIO_AFRH_10_A0 ((uint32_t)0x00000000)
#define GPIO_AFRH_10_A1 ((uint32_t)0x00000100)
#define GPIO_AFRH_10_A2 ((uint32_t)0x00000200)
#define GPIO_AFRH_10_A3 ((uint32_t)0x00000300)
#define GPIO_AFRH_10_A4 ((uint32_t)0x00000400)
#define GPIO_AFRH_10_A5 ((uint32_t)0x00000500)
#define GPIO_AFRH_10_A6 ((uint32_t)0x00000600)
#define GPIO_AFRH_10_A7 ((uint32_t)0x00000700)

#define GPIO_AFRH_11_A0 ((uint32_t)0x00000000)
#define GPIO_AFRH_11_A1 ((uint32_t)0x00001000)
#define GPIO_AFRH_11_A2 ((uint32_t)0x00002000)
#define GPIO_AFRH_11_A3 ((uint32_t)0x00003000)
#define GPIO_AFRH_11_A4 ((uint32_t)0x00004000)
#define GPIO_AFRH_11_A5 ((uint32_t)0x00005000)
#define GPIO_AFRH_11_A6 ((uint32_t)0x00006000)
#define GPIO_AFRH_11_A7 ((uint32_t)0x00007000)

#define GPIO_AFRH_12_A0 ((uint32_t)0x00000000)
#define GPIO_AFRH_12_A1 ((uint32_t)0x00010000)
#define GPIO_AFRH_12_A2 ((uint32_t)0x00020000)
#define GPIO_AFRH_12_A3 ((uint32_t)0x00030000)
#define GPIO_AFRH_12_A4 ((uint32_t)0x00040000)
#define GPIO_AFRH_12_A5 ((uint32_t)0x00050000)
#define GPIO_AFRH_12_A6 ((uint32_t)0x00060000)
#define GPIO_AFRH_12_A7 ((uint32_t)0x00070000)

#define GPIO_AFRH_13_A0 ((uint32_t)0x00000000)
#define GPIO_AFRH_13_A1 ((uint32_t)0x00100000)
#define GPIO_AFRH_13_A2 ((uint32_t)0x00200000)
#define GPIO_AFRH_13_A3 ((uint32_t)0x00300000)
#define GPIO_AFRH_13_A4 ((uint32_t)0x00400000)
#define GPIO_AFRH_13_A5 ((uint32_t)0x00500000)
#define GPIO_AFRH_13_A6 ((uint32_t)0x00600000)
#define GPIO_AFRH_13_A7 ((uint32_t)0x00700000)

#define GPIO_AFRH_14_A0 ((uint32_t)0x00000000)
#define GPIO_AFRH_14_A1 ((uint32_t)0x01000000)
#define GPIO_AFRH_14_A2 ((uint32_t)0x02000000)
#define GPIO_AFRH_14_A3 ((uint32_t)0x03000000)
#define GPIO_AFRH_14_A4 ((uint32_t)0x04000000)
#define GPIO_AFRH_14_A5 ((uint32_t)0x05000000)
#define GPIO_AFRH_14_A6 ((uint32_t)0x06000000)
#define GPIO_AFRH_14_A7 ((uint32_t)0x07000000)

#define GPIO_AFRH_15_A0 ((uint32_t)0x00000000)
#define GPIO_AFRH_15_A1 ((uint32_t)0x10000000)
#define GPIO_AFRH_15_A2 ((uint32_t)0x20000000)
#define GPIO_AFRH_15_A3 ((uint32_t)0x30000000)
#define GPIO_AFRH_15_A4 ((uint32_t)0x40000000)
#define GPIO_AFRH_15_A5 ((uint32_t)0x50000000)
#define GPIO_AFRH_15_A6 ((uint32_t)0x60000000)
#define GPIO_AFRH_15_A7 ((uint32_t)0x70000000)

/* GPIOA Registers */
#define GPIOA_MODER     (*(__IO uint32_t*)0x48000000)
#define GPIOA_OTYPER    (*(__IO uint16_t*)0x48000004)
#define GPIOA_OSPEEDR   (*(__IO uint32_t*)0x48000008)
#define GPIOA_PUPDR     (*(__IO uint32_t*)0x4800000C)
#define GPIOA_IDR       (*(__IO uint16_t*)0x48000010)
#define GPIOA_ODR       (*(__IO uint16_t*)0x48000014)
#define GPIOA_BSRR      (*(__IO uint32_t*)0x48000018)
#define GPIOA_LCKR      (*(__IO uint32_t*)0x4800001C)
#define GPIOA_AFRL      (*(__IO uint32_t*)0x48000020)
#define GPIOA_AFRH      (*(__IO uint32_t*)0x48000024)
#define GPIOA_BRR       (*(__IO uint16_t*)0x48000028)

/* GPIOB Registers */
#define GPIOB_MODER     (*(__IO uint32_t*)0x48000400)
#define GPIOB_OTYPER    (*(__IO uint16_t*)0x48000404)
#define GPIOB_OSPEEDR   (*(__IO uint32_t*)0x48000408)
#define GPIOB_PUPDR     (*(__IO uint32_t*)0x4800040C)
#define GPIOB_IDR       (*(__IO uint16_t*)0x48000410)
#define GPIOB_ODR       (*(__IO uint16_t*)0x48000414)
#define GPIOB_BSRR      (*(__IO uint32_t*)0x48000418)
#define GPIOB_LCKR      (*(__IO uint32_t*)0x4800041C)
#define GPIOB_AFRL      (*(__IO uint32_t*)0x48000420)
#define GPIOB_AFRH      (*(__IO uint32_t*)0x48000424)
#define GPIOB_BRR       (*(__IO uint16_t*)0x48000428)

// SECTION: SPI \\

/* SPIx_CR1 */
#define SPI_CR1_DIR_1TX  ((uint16_t)0xC000)
#define SPI_CR1_DIR_1RX  ((uint16_t)0x8000)
#define SPI_CR1_DIR_2RX  ((uint16_t)0x0400)
#define SPI_CR1_DIR_2FD  ((uint16_t)0x0000)

#define SPI_CR1_MOD_MS   ((uint16_t)0x0104)
#define SPI_CR1_MOD_SL   ((uint16_t)0x0000)

#define SPI_CR1_CPOL_L   ((uint16_t)0x0000)
#define SPI_CR1_CPOL_H   ((uint16_t)0x0002) 

#define SPI_CR1_CPHA_1   ((uint16_t)0x0000)
#define SPI_CR1_CPHA_2   ((uint16_t)0x0001) 

#define SPI_CR1_MODE_0   (SPI_CR1_CPOL_L | SPI_CR1_CPHA_1)
#define SPI_CR1_MODE_1   (SPI_CR1_CPOL_L | SPI_CR1_CPHA_2)
#define SPI_CR1_MODE_2   (SPI_CR1_CPOL_H | SPI_CR1_CPHA_1)
#define SPI_CR1_MODE_3   (SPI_CR1_CPOL_H | SPI_CR1_CPHA_2)

#define SPI_CR1_NSS_S    ((uint16_t)0x0200)
#define SPI_CR1_NSS_H    ((uint16_t)0x0200)

#define SPI_CR1_PSC_2    ((uint16_t)0x0000)
#define SPI_CR1_PSC_4    ((uint16_t)0x0008)
#define SPI_CR1_PSC_8    ((uint16_t)0x0010)
#define SPI_CR1_PSC_16   ((uint16_t)0x0018)
#define SPI_CR1_PSC_32   ((uint16_t)0x0020)
#define SPI_CR1_PSC_64   ((uint16_t)0x0028)
#define SPI_CR1_PSC_128  ((uint16_t)0x0030)
#define SPI_CR1_PSC_256  ((uint16_t)0x0038)


/* SPIx_CR2 */
#define SPI_CR2_DS_4B    ((uint16_t)0x0300)
#define SPI_CR2_DS_5B    ((uint16_t)0x0400)
#define SPI_CR2_DS_6B    ((uint16_t)0x0500)
#define SPI_CR2_DS_7B    ((uint16_t)0x0600)
#define SPI_CR2_DS_8B    ((uint16_t)0x0700)
#define SPI_CR2_DS_9B    ((uint16_t)0x0800)
#define SPI_CR2_DS_10B   ((uint16_t)0x0900)
#define SPI_CR2_DS_11B   ((uint16_t)0x0A00)
#define SPI_CR2_DS_12B   ((uint16_t)0x0B00)
#define SPI_CR2_DS_13B   ((uint16_t)0x0C00)
#define SPI_CR2_DS_14B   ((uint16_t)0x0D00)
#define SPI_CR2_DS_15B   ((uint16_t)0x0E00)
#define SPI_CR2_DS_16B   ((uint16_t)0x0F00)

/* SPI1 registers */
#define SPI1_CR1         (*(__IO uint32_t*)0x40013000)
#define SPI1_CR2         (*(__IO uint32_t*)0x40013004)
#define SPI1_SR          (*(__IO uint32_t*)0x40013008)
#define SPI1_DR          (*(__IO uint32_t*)0x4001300C)
#define SPI1_DR8         (*(__IO uint8_t*)0x4001300C)

// SECTION: USART \\

/* USARTx_CR1 */
#define USART_CR1_WL_8    ((uint32_t)0x00000000)
#define USART_CR1_WL_9    ((uint32_t)0x00001000)
#define USART_CR1_WL_7    ((uint32_t)0x10001000)

#define USART_CR1_PAR_NO  ((uint32_t)0x00000000)
#define USART_CR1_PAR_EV  ((uint32_t)0x00000400)
#define USART_CR1_PAR_OD  ((uint32_t)0x00000600)

#define USART_CR1_MODE_R  ((uint32_t)0x00000004)
#define USART_CR1_MODE_T  ((uint32_t)0x00000008)

/* USARTx_CR2 */
#define USART_CR2_ST_1    ((uint32_t)0x00000000)
#define USART_CR2_ST_2    ((uint32_t)0x00002000)
#define USART_CR2_ST_1_5  ((uint32_t)0x00003000)

/* USARTx_CR3 */
#define USART_CR3_FL_NO   ((uint32_t)0x00000000)
#define USART_CR3_FL_RTS  ((uint32_t)0x00000100)   
#define USART_CR3_FL_CTS  ((uint32_t)0x00000200) 
#define USART_CR3_FL_R_C  ((uint32_t)0x00000300) 

/* BRR calculate (over-16 only!) */
#define _calc_BRR(baud) (CPU_CLOCK / baud)

/* Pre-calculated BRR values for CPU_CLOCK = 48MHz*/
#define USART_BRR_2400    ((uint16_t)0x4E20)
#define USART_BRR_9600    ((uint16_t)0x1388)
#define USART_BRR_19200   ((uint16_t)0x09C4)
#define USART_BRR_38400   ((uint16_t)0x04E2)
#define USART_BRR_57600   ((uint16_t)0x0341)
#define USART_BRR_115200  ((uint16_t)0x01A1)
#define USART_BRR_230400  ((uint16_t)0x00D0)
#define USART_BRR_460800  ((uint16_t)0x0068)
#define USART_BRR_921600  ((uint16_t)0x0034)
#define USART_BRR_2MBPS   ((uint16_t)0x0018)
#define USART_BRR_3MBPS   ((uint16_t)0x0010)


// SECTION: ADC \\

/* ADCx_CFGR1 */
#define ADC_CFGR1_RES_12  ((uint32_t)0x00000000)
#define ADC_CFGR1_RES_10  ((uint32_t)0x00000008)
#define ADC_CFGR1_RES_8   ((uint32_t)0x00000010)
#define ADC_CFGR1_RES_6   ((uint32_t)0x00000018)

#define ADC_CFGR1_ALIGN_L ((uint32_t)0x00000020)
#define ADC_CFGR1_ALIGN_R ((uint32_t)0x00000000)

/* ADCx_CHSELR */
#define ADC_CH_0          ((uint32_t)0x00000001) 
#define ADC_CH_1          ((uint32_t)0x00000002) 
#define ADC_CH_2          ((uint32_t)0x00000004)
#define ADC_CH_3          ((uint32_t)0x00000008) 
#define ADC_CH_4          ((uint32_t)0x00000010) 
#define ADC_CH_5          ((uint32_t)0x00000020) 
#define ADC_CH_6          ((uint32_t)0x00000040)
#define ADC_CH_7          ((uint32_t)0x00000080)
#define ADC_CH_8          ((uint32_t)0x00000100) 
#define ADC_CH_9          ((uint32_t)0x00000200) 
#define ADC_CH_10         ((uint32_t)0x00000400)
#define ADC_CH_11         ((uint32_t)0x00000800) 
#define ADC_CH_12         ((uint32_t)0x00001000)
#define ADC_CH_13         ((uint32_t)0x00002000) 
#define ADC_CH_14         ((uint32_t)0x00004000)
#define ADC_CH_15         ((uint32_t)0x00008000) 
#define ADC_CH_16         ((uint32_t)0x00010000)
#define ADC_CH_17         ((uint32_t)0x00020000)
#define ADC_CH_18         ((uint32_t)0x00040000)

/* ADCx_SMPR */
#define ADC_SMPR_TIM_1    ((uint32_t)0x00000000)
#define ADC_SMPR_TIM_7    ((uint32_t)0x00000001)
#define ADC_SMPR_TIM_13   ((uint32_t)0x00000002)
#define ADC_SMPR_TIM_28   ((uint32_t)0x00000003)
#define ADC_SMPR_TIM_41   ((uint32_t)0x00000004)
#define ADC_SMPR_TIM_55   ((uint32_t)0x00000005)
#define ADC_SMPR_TIM_71   ((uint32_t)0x00000006)
#define ADC_SMPR_TIM_239  ((uint32_t)0x00000007)

/* ADC1 add-on's */
#define _adcen()          ADC1->CR |= ADC_CR_ADEN
#define _adc_start()      ADC1->CR |= ADC_CR_ADSTART
#define ADC_CONVERTING    (!(ADC1->ISR & ADC_ISR_EOC))

//SECTION: TIM2\\

/* Registers */
#define TIM2_CR1   (*(__IO uint16_t*)0x40000000)
#define TIM2_CR2   (*(__IO uint16_t*)0x40000004)
#define TIM2_SMCR  (*(__IO uint16_t*)0x40000008)
#define TIM2_DIER  (*(__IO uint16_t*)0x4000000C)
#define TIM2_SR    (*(__IO uint16_t*)0x40000010)
#define TIM2_EGR   (*(__IO uint16_t*)0x40000014)
#define TIM2_CCMR1 (*(__IO uint16_t*)0x40000018)
#define TIM2_CCMR2 (*(__IO uint16_t*)0x4000001C)
#define TIM2_CCER  (*(__IO uint16_t*)0x40000020)
#define TIM2_CNT   (*(__IO uint32_t*)0x40000024)
#define TIM2_PSC   (*(__IO uint16_t*)0x40000028)
#define TIM2_ARR   (*(__IO uint32_t*)0x4000002C)
#define TIM2_RCR   (*(__IO uint16_t*)0x40000030)
#define TIM2_CCR1  (*(__IO uint32_t*)0x40000034)
#define TIM2_CCR2  (*(__IO uint32_t*)0x40000038)
#define TIM2_CCR3  (*(__IO uint32_t*)0x4000003C)
#define TIM2_CCR4  (*(__IO uint32_t*)0x40000040)
#define TIM2_BDTR  (*(__IO uint16_t*)0x40000044)
#define TIM2_DCR   (*(__IO uint16_t*)0x40000048)
#define TIM2_DMAR  (*(__IO uint16_t*)0x4000004C)
#define TIM2_OR    (*(__IO uint16_t*)0x40000050)

#define  RCC_APB1ENR_TIM2EN                  ((uint32_t)0x00000001)   

#endif //end of defines.h
