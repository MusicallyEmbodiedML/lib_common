#ifndef __COMMON_DEFS_H__
#define __COMMON_DEFS_H__

#if defined(__cplusplus) || defined(__XC__)
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

typedef struct {
    float potX;
    float potY;
    float potRotate;
} ts_joystick_read;

typedef struct {
    size_t note_number;
    float velocity;
} ts_midi_note;

/**
 * UI elements
 */

typedef enum {
    joystick_potX,
    joystick_potY,
    joystick_potRotate,
    joystick_nPots
} te_joystick_pot;

typedef enum {
    toggle_training,   // 0
    button_randomise,  // 1
    toggle_savedata,   // 2
    button_cleardata,  // 3
    button_clearmodel, // 4
    toggle_discretise, // 5
    toggle_complex,    // 6
    toggle_explmode,   // 7
    toggle_dataset,    // 8
    toggle_model,      // 9
    button_nButtons
} te_button_idx;

typedef enum {
    slider_randomSpeed,
    slider_nIterations,
    slider_nSliders
} te_slider_idx;

/**
 * Behavioural elements/flags
 */

typedef enum {
    mode_inference,
    mode_training,
    mode_nModes
} te_nn_mode;

typedef enum {
    expl_mode_nnweights,
    expl_mode_pretrain,
    expl_mode_zoom,
    expl_nModes
} te_expl_mode;

typedef enum {
    ui_last_error,
    ui_nElements,
} te_ui_info;

typedef enum {
    app_id_unknown,
    app_id_fmsynth,
    app_id_euclidean,
    app_id_multifx,
    app_id_machinelisten,
    app_nIDs
} te_app_id;

typedef enum {
    midi_noteon,
    midi_noteoff,
    midi_nCommands
} te_midi_command;

#define kMaxDatasets    4
#define kMaxModels      4

/**
 * State structure
 */


typedef struct {

    // 32-bit parameters
    uint32_t n_iterations;
    float last_error;
    float exploration_range;

    // 8-bit parameters
    te_app_id app_id;
    uint8_t current_dataset;
    uint8_t current_model;
    te_nn_mode current_nn_mode;
    te_expl_mode current_expl_mode;

} ts_app_state;


#if defined(__cplusplus) || defined(__XC__)
}
#endif

#endif  // __COMMON_DEFS_H__
