#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/cortex.h>


int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	rcc_clock_setup_in_hsi_out_48mhz();
	rcc_periph_clock_enable(RCC_GPIOA);
	rcc_periph_reset_pulse(RST_GPIOA);

	gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO10);
	gpio_set(GPIOA, GPIO10);

	for(;;) {
		uint32_t j;
		for (j=0; j<8000000;j++)
			__asm__("nop");
		gpio_toggle(GPIOA, GPIO10);
	}
}
