
#ifndef __MEAS_CENTER_VIEW_H__
#define __MEAS_CENTER_VIEW_H__

#include "lvgl.h"

typedef struct {
    lv_obj_t * cont;
    lv_obj_t * lableValue;
    lv_obj_t * lableUnit;
    lv_style_t style;
} MainShow;

typedef struct {
    lv_obj_t * cont;
    lv_obj_t * labelValue1;
	lv_obj_t * labelValue2;
	lv_obj_t * labelValue3;
	lv_obj_t * labelValue4;
} Sidebar;

typedef struct {
    lv_obj_t * cont;
    lv_style_t style;

    MainShow mainShow;
    Sidebar sidebar;
} MeasCenterSence;

extern MeasCenterSence MeasSence;

extern void measCenterViewCreate(lv_obj_t * root);
extern void mainShowViewCreate(lv_obj_t * par);
extern void sidebarViewCreate(lv_obj_t * par);

extern void measCenterLoadView(lv_obj_t * root);

#endif