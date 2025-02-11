#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"

const uint PIN_SERVO_MOTOR = 22;

// Protótipos de funções
int64_t off_alarm_callback(alarm_id_t id, void *userData);
void infinite_moviment();
// Possiveis movimentos do servo motor
const uint8_t MOVE_180_DEGREES = 1, MOVE_90_DEGREES = 2, MOVE_0_DEGREES = 3;

// Armazena o id do alarme atual em vigor
volatile int64_t CURRENT_ALARM = 0;

// Armazena o movimento que deve ser realizado no próximo alarme
volatile uint8_t NEXT_MOVEMENT = MOVE_180_DEGREES;

// Definição de alguns parâmetros do PWM
const uint WRAP = 62000, INTEGER_DIV = 40;

// Váriavel responsável por aumentar o duty cycle
uint16_t STEP = WRAP * 0.025;

// Controla o incremento e decremento do duty cycle
bool CAN_INCREMENT = true, ACTIVE_INFINITE = false;

int main()
{

    uint SLICE_PIN = pwm_gpio_to_slice_num(PIN_SERVO_MOTOR);

    gpio_set_function(PIN_SERVO_MOTOR, GPIO_FUNC_PWM);
    pwm_set_wrap(SLICE_PIN,WRAP);
    pwm_set_clkdiv(SLICE_PIN, INTEGER_DIV);

    pwm_set_enabled(SLICE_PIN, 1);
    //PWMf = clock/(intDiv*wrap)
    stdio_init_all();

    CURRENT_ALARM = add_alarm_in_ms(1000, off_alarm_callback, NULL, false);

    while (true)
    {
        if (ACTIVE_INFINITE)
        {
            infinite_moviment();
        }
        sleep_ms(10);
    }
}
int64_t off_alarm_callback(alarm_id_t id, void *userData)
{
    switch (NEXT_MOVEMENT)
    {
    case MOVE_180_DEGREES:
        pwm_set_gpio_level(PIN_SERVO_MOTOR, WRAP * 0.12);
        NEXT_MOVEMENT = MOVE_90_DEGREES;
        cancel_alarm(CURRENT_ALARM);
        CURRENT_ALARM = add_alarm_in_ms(5000, off_alarm_callback, NULL, false);
        return 0;

    case MOVE_90_DEGREES:
        pwm_set_gpio_level(PIN_SERVO_MOTOR, WRAP * 0.0735);
        NEXT_MOVEMENT = MOVE_0_DEGREES;
        cancel_alarm(CURRENT_ALARM);
        CURRENT_ALARM = add_alarm_in_ms(5000, off_alarm_callback, NULL, false);
        return 0;
    case MOVE_0_DEGREES:
        pwm_set_gpio_level(PIN_SERVO_MOTOR, WRAP * 0.025);
        NEXT_MOVEMENT = 0;
        cancel_alarm(CURRENT_ALARM);

        CURRENT_ALARM = add_alarm_in_ms(5000, off_alarm_callback, NULL, false);
        return 0;
    default:
        ACTIVE_INFINITE = true;
    }
}
void infinite_moviment()
{
    if (CAN_INCREMENT)
    {
        //Verifica se chegou ao nivel máximo
        if (STEP <= WRAP * 0.12)
        {
            STEP += WRAP * 0.00025;
            pwm_set_gpio_level(PIN_SERVO_MOTOR, STEP);
            return;
        }
        CAN_INCREMENT = false;
        return;
    }
    //Verifica se chegou ao nivel mínimo
    if (STEP >= WRAP * 0.025)
    {
        STEP -= WRAP * 0.00025;
        pwm_set_gpio_level(PIN_SERVO_MOTOR, STEP);
        return;
    }
    CAN_INCREMENT = true;
}
