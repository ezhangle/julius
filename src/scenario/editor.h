#ifndef SCENARIO_EDITOR_H
#define SCENARIO_EDITOR_H

typedef struct {
    int year;
    int resource;
    int amount;
    int deadline_years;
    int favor;
} editor_request;

typedef struct {
    int year;
    int type;
    int amount;
    int from;
    int attack_type;
} editor_invasion;

void scenario_editor_request_get(int index, editor_request *request);

void scenario_editor_invasion_get(int index, editor_invasion *invasion);

void scenario_editor_cycle_image(int forward);

void scenario_editor_cycle_climate(void);

void scenario_editor_set_enemy(int enemy_id);

#endif // SCENARIO_EDITOR_H
