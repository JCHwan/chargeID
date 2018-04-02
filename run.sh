
edep-sim -e200 -u -C -g 3DST_beam_222_Bfield.gdml -o 3DST_222_particleGun_${inn}_30cone_0.4Bfield.root inputs/${inn}_30cone.mac

for i in $(seq 0 1 0)
do
        root -l -q Transfer_grid.C 3DST_222_particleGun_${inn}_30cone_0.4Bfield_sample$i 3DST_222_particleGun_${inn}_30cone_0.4Bfield $i
done

g++ -std=c++11 -o main_electron ND280UpRecoTrack.cc main_electron2.cc `root-config --cflags --glibs`

for i in $(seq 0 1 0)
do
        for j in 100 200
        do
                echo $i
                echo $j
                ./main_electron 3DST_222_particleGun_${inn}_30cone_0.4Bfield_sample$i $j $i
        done
done