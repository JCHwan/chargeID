# chargeID
  This codes are for charge separation in 3DST

# Main code
  'ND280UpRecoTrack.cc' and 'main_electron2.cc' are main codes and they should be run after Transfer_grid.C.
  Charge separation algorithm is in 'void ND280UpPID::ChargeID(Tgraph g)'.
  The function works well with the below condition.
  
  1. Magnetic field is in +X direction.
  2. TGraph point's horizontal information: Z position of hit.
  3. TGraph point's vertical information: Y position of hit.

  'main_electron2.cc' are made with satisfying above condition.

# test code
  'find_center2.C' is a test code that can check charge separation algothm event by event. You can run it after edep-sim.

