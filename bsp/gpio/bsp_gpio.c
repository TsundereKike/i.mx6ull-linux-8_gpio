#include "bsp_gpio.h"
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    if(config->direction == kGPIO_DigitalInput)
    {
        base->GDIR &= ~(1<<pin);
    }
    else
    {
        base->GDIR |= (1<<pin);
        gpio_pin_wirte(GPIO5, pin, config->outputLogic);
    }
}
void gpio_pin_wirte(GPIO_Type *base, int pin, int value)
{
    if(value==0U)
    {
        base->DR &= ~(1U<<pin);
    }
    else
    {
        base->DR |= (1U<<pin);
    }
    
}
int gpio_pin_read(GPIO_Type *base, int pin)
{
    return (((base->DR) >> pin) & 0x01);
}