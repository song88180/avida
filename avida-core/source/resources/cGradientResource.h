//
//  cGradientResource.hpp
//  avida-core (static)
//
//  Created by Matthew Rupp on 1/15/18.
//

#ifndef cGradientResource_h
#define cGradientResource_h

#include "cAbstractResource.h"
#include "cAbstractResourceAcct.h"

class cGradientResourceAcct;

class cGradientResource : public cAbstractResource
{
  friend cGradientResourceAcct;
  
  private:
    cGradientResource();
    cGradientResource(const cGradientResource&);
    cGradientResource& operator=(const cGradientResource&);

  protected:
    int m_peaks; //JW
    double m_min_height; //JW
    double m_height_range; //JW
    double m_min_radius; //JW
    double m_radius_range; //JW
    double m_ah; //JW
    double m_ar; //JW
    double m_acx; //JW
    double m_acy; //JW
    double m_hstepscale; //JW
    double m_rstepscale; //JW
    double m_cstepscalex; //JW
    double m_cstepscaley; //JW
    double m_hstep; //JW
    double m_rstep; //JW
    double m_cstepx; //JW
    double m_cstepy; //JW
    int m_update_dynamic; //JW
    int m_peakx;
    int m_peaky;
    int m_height;
    int m_spread;    
    double m_plateau;
    int m_decay;
    int m_max_x;
    int m_max_y;
    int m_min_x;
    int m_min_y;
    double m_move_a_scalar;
    int m_updatestep; 
    int m_halo;
    int m_halo_inner_radius;
    int m_halo_width;
    int m_halo_anchor_x;
    int m_halo_anchor_y;
    int m_move_speed;
    int m_move_resistance;
    double m_plateau_inflow;
    double m_plateau_outflow;
    double m_cone_inflow;
    double m_cone_outflow;
    double m_gradient_inflow;
    int m_is_plateau_common;
    double m_floor;
    int m_habitat;
    int m_min_size;
    int m_max_size;
    int m_config;
    int m_count; 
    double m_resistance;
    double m_init_plat;
    double m_threshold;
    int m_refuge;
    Apto::Array<int> cell_id_list;
    double m_predator_odds;
    bool m_predator;
    double m_guard_juvs_per;

    
  public:
    cGradientResource(int id, const cString& name)
    : cAbstractResource(id, name) {}
    
    ADD_RESOURCE_PROP(int, Peaks, m_peaks);
    ADD_RESOURCE_PROP(double, MinHeight, m_min_height);
    ADD_RESOURCE_PROP(double, HeightRange, m_height_range);
    ADD_RESOURCE_PROP(double, MinRadius, m_min_radius);
    ADD_RESOURCE_PROP(double, RadiusRange, m_radius_range);
    ADD_RESOURCE_PROP(double, AH, m_ah);
    ADD_RESOURCE_PROP(double, AR, m_ar);
    ADD_RESOURCE_PROP(double, ACX, m_acx);
    ADD_RESOURCE_PROP(double, ACY, m_acy);
    ADD_RESOURCE_PROP(double, HStepScale, m_hstepscale);
    ADD_RESOURCE_PROP(double, RStepScale, m_rstepscale);
    ADD_RESOURCE_PROP(double, CStepScaleX, m_cstepscalex);
    ADD_RESOURCE_PROP(double, CStepScaleY, m_cstepscaley);
    ADD_RESOURCE_PROP(double, HStep, m_hstep);
    ADD_RESOURCE_PROP(double, RStep, m_rstep);
    ADD_RESOURCE_PROP(double, CStepX, m_cstepx);
    ADD_RESOURCE_PROP(double, CStepY, m_cstepy);
    ADD_RESOURCE_PROP(int, UpdateDynamic, m_update_dynamic);
    ADD_RESOURCE_PROP(int, PeakX, m_peakx);
    ADD_RESOURCE_PROP(int, PeakY, m_peaky);
    ADD_RESOURCE_PROP(int, Height, m_height);
    ADD_RESOURCE_PROP(int, Spread, m_spread);
    ADD_RESOURCE_PROP(double, Plateau, m_plateau);
    ADD_RESOURCE_PROP(int, Decay, m_decay);
    ADD_RESOURCE_PROP(int, MaxX, m_max_x);
    ADD_RESOURCE_PROP(int, MaxY, m_max_y);
    ADD_RESOURCE_PROP(int, MinX, m_min_x);
    ADD_RESOURCE_PROP(int, MinY, m_min_y);
    ADD_RESOURCE_PROP(double, MoveAScalar, m_move_a_scalar);
    ADD_RESOURCE_PROP(int, UpdateStep, m_updatestep);
    ADD_RESOURCE_PROP(int, Halo, m_halo);
    ADD_RESOURCE_PROP(int, HaloInnerRadius, m_halo_inner_radius);
    ADD_RESOURCE_PROP(int, HaloAnchorX, m_halo_anchor_x);
    ADD_RESOURCE_PROP(int, HaloAnchorY, m_halo_anchor_y);
    ADD_RESOURCE_PROP(int, MoveSpeed, m_move_speed);
    ADD_RESOURCE_PROP(int, MoveResistance, m_move_resistance);
    ADD_RESOURCE_PROP(double, PlateauInflow, m_plateau_inflow);
    ADD_RESOURCE_PROP(double, PlateauOutflow, m_plateau_outflow);
    ADD_RESOURCE_PROP(double, ConeInflow, m_cone_inflow);
    ADD_RESOURCE_PROP(double, ConeOutflow, m_cone_outflow);
    ADD_RESOURCE_PROP(double, GradientInflow, m_gradient_inflow);
    ADD_RESOURCE_PROP(int, IsPlateauCommon, m_is_plateau_common);
    ADD_RESOURCE_PROP(double, Floor, m_floor);
    ADD_RESOURCE_PROP(int, Habitat, m_habitat);
    ADD_RESOURCE_PROP(int, MinSize, m_min_size);
    ADD_RESOURCE_PROP(int, MaxSize, m_max_size);
    ADD_RESOURCE_PROP(int, Count, m_count);
    ADD_RESOURCE_PROP(double, Resistance, m_resistance);
    ADD_RESOURCE_PROP(double, InitialPlateau, m_init_plat);
    ADD_RESOURCE_PROP(double, Threshold, m_threshold);
    ADD_RESOURCE_PROP(double, PredatorOdds, m_predator_odds);
    ADD_RESOURCE_PROP(double, Damage, m_damage);
    ADD_RESOURCE_PROP(bool, IsPath, m_is_path);

};

class cWorld;
class cPopulation;
class cAvidaContext;

class cGradientResourceAcct : public cAbstractResourceAcct
{
  protected:
   cWorld* m_world;
   cPopulation* m_pop;
  
  // Internal Values
  bool m_initial;
  doublt m_initial_plat;
  
  double m_move_y_scaler;
  
  int m_counter;
  int m_move_counter;
  int m_topo_counter;
  int m_movesignx;
  int m_movesigny;
  
  int m_old_peakx;
  int m_old_peaky;
  
  int m_halo_dir;
  int m_changling;
  bool m_just_reset;
  double m_past_height;
  double m_current_height;
  double m_ave_plat_cell_loss;
  double m_common_plat_height;
  int m_skip_moves;
  int m_skip_counter;
  Apto::Array<double> m_plateau_array;
  Apto::Array<int> m_plateau_cell_IDs;
  Apto::Array<int> m_wall_cells;
  
  double m_mean_plat_inflow;
  double m_var_plat_inflow;
  
  double m_pred_odds;
  bool m_predator;
  double m_death_odds;
  bool m_deadly;
  int m_path;
  int m_hammer;
  int m_guarded_juvs_per_adult;
  
  bool m_probabilistic;
  Apto::Array<int> m_prob_res_cells;

  int m_min_usedx;
  int m_min_usedy;
  int m_max_usedx;
  int m_max_usedy;
    
public:
  cGradientResourceAcct(cGradientResource& res, cWorld* world);
  ~cGradientResourceAcct();

  void UpdateCount(cAvidaContext& ctx);
  
  void SetGradInitialPlat(double plat_val);
 
  void SetGradPlatVarInflow(cAvidaContext& ctx, double mean, double variance, int type);
  
  void SetPredatoryResource(double odds, int juvsper);
  template<class T> void UpdatePredatoryRes(cAvidaContext& ctx);

  void UpdateDamagingRes(cAvidaContext& ctx);
  void SetDeadlyRes(double odds) { m_death_odds = odds; m_deadly = (m_death_odds != 0); }
  void SetIsPath(bool path) { m_path = path; }
  void UpdateDeadlyRes(cAvidaContext& ctx);
  
  void SetProbabilisticResource(cAvidaContext& ctx, double initial, double inflow, double outflow, double lambda, double theta, int x, int y, int num_cells);
  void BuildProbabilisticRes(cAvidaContext& ctx, double lambda, double theta, int x, int y, int num_cells);
  void UpdateProbabilisticRes();
 
  void ResetGradRes(cAvidaContext& ctx, int worldx, int worldy); 
  
  Apto::Array<int>* GetWallCells() { return &m_wall_cells; }
  int GetMinUsedX() { return m_min_usedx; }
  int GetMinUsedY() { return m_min_usedy; }
  int GetMaxUsedX() { return m_max_usedx; }
  int GetMaxUsedY() { return m_max_usedy; }
  
private:
  void fillinResourceValues();
  void updatePeakRes(cAvidaContext& ctx);
  void moveRes(cAvidaContext& ctx);
  int setHaloOrbit(cAvidaContext& ctx, int current_orbit);
  void setPeakMoveMovement(cAvidaContext& ctx);
  void moveHaloPeak(int current_orbit);
  void confirmHaloPeak();
  void movePeak();
  void generatePeak(cAvidaContext& ctx);
  void getCurrentPlatValues();
  void generateBarrier(cAvidaContext& ctx);
  void generateHills(cAvidaContext& ctx);    
  void updateBounds(int x, int y);
  void resetUsedBounds();
  void clearExistingProbRes();
  
  inline void setHaloDirection(cAvidaContext& ctx);
  
};


template<class T>
void cGradientResource::UpdatePredatoryRes(cAvidaContext& ctx)
{
  // kill off up to 1 org per update within the predator radius (plateau area), 
  //with prob of death for selected prey = m_pred_odds
  if (m_predator) {
    for (int i = 0; i < m_plateau_cell_IDs.GetSize(); i ++) {
      if (Element(m_plateau_cell_IDs[i]).GetAmount() >= 1) {
        T->ExecutePredatoryResource(ctx, m_plateau_cell_IDs[i], m_pred_odds, m_guarded_juvs_per_adult, m_hammer);
      }
    }
  }
}
#endif /* cGradientResource_h */
