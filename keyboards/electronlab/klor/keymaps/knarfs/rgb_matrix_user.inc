RGB_MATRIX_EFFECT(layer_indicator_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static const rgb_t layer_colors[MATRIX_ROWS][MATRIX_COLS] = {
    {RGB_OFF,  RGB_RED, RGB_RED, RGB_RED, RGB_RED, RGB_RED, },            //{RGB_MAGENTA, RGB_MAGENTA, RGB_MAGENTA, RGB_MAGENTA, RGB_MAGENTA, },
    {RGB_BLUE, RGB_CYAN, RGB_CYAN, RGB_CYAN, RGB_CYAN, RGB_BLUE, },       //{RGB_BLUE, RGB_CYAN, RGB_CYAN, RGB_CYAN, RGB_CYAN, RGB_BLUE, },
    {RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, }, //{RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_BLUE, },
    {           RGB_OFF, RGB_GOLD, RGB_GOLD, RGB_GOLD, RGB_GOLD, RGB_OFF },       //{RGB_GOLD, RGB_GOLD, RGB_GOLD, RGB_GOLD, },



{RGB_MAGENTA, RGB_MAGENTA, RGB_MAGENTA, RGB_MAGENTA, RGB_MAGENTA, RGB_OFF},
{RGB_BLUE, RGB_CYAN, RGB_CYAN, RGB_CYAN, RGB_CYAN, RGB_BLUE, },
{RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_GREEN, RGB_BLUE, },
{RGB_OFF, RGB_GOLD, RGB_GOLD, RGB_GOLD, RGB_GOLD, RGB_OFF},
};

static bool layer_indicator_effect(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {

            uint8_t led = g_led_config.matrix_co[row][col];
            uprintf("Led: %2u / %2u: %u\n", row, col, led);
            if (led == NO_LED) continue;
            if (led < led_min || led >= led_max) continue;

            rgb_t c = layer_colors[row][col];
            rgb_matrix_set_color(led, c.r, c.g, c.b);
        }
    }
    //return false;
    return rgb_matrix_check_finished_leds(led_max);
}

#endif
