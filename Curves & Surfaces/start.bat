curve_editor -input .\input\spline01_bezier.txt -gui -curve_tessellation 30
curve_editor -input .\input\spline02_bspline.txt -gui -curve_tessellation 30
curve_editor -input .\input\spline01_bezier.txt -output_bezier .\output\output01_bezier.txt
curve_editor -input .\input\spline01_bezier.txt -output_bspline .\output\output01_bspline.txt
curve_editor -input .\input\spline02_bspline.txt -output_bezier .\output\output02_bezier.txt
curve_editor -input .\input\spline02_bspline.txt -output_bspline .\output\output02_bspline.txt
curve_editor -input .\output\output01_bezier.txt -gui -curve_tessellation 30
curve_editor -input .\output\output01_bspline.txt -gui -curve_tessellation 30
curve_editor -input .\output\output02_bezier.txt -gui -curve_tessellation 30
curve_editor -input .\output\output02_bspline.txt -gui -curve_tessellation 30
curve_editor -input .\input\spline03_bezier.txt -gui -curve_tessellation 30
curve_editor -input .\input\spline04_bspline.txt -gui -curve_tessellation 30
curve_editor -input .\input\spline05_bspline_dups.txt -gui -curve_tessellation 30
curve_editor -input .\input\spline06_torus.txt -curve_tessellation 4 -gui
curve_editor -input .\input\spline06_torus.txt -curve_tessellation 4 -revolution_tessellation 10 -output .\output\torus_low.obj
curve_editor -input .\input\spline06_torus.txt -curve_tessellation 30 -revolution_tessellation 60 -output .\output\torus_high.obj
raytracer -input .\input\scene06_torus_low.txt -gui -size 300 300
raytracer -input .\input\scene06_torus_high.txt -gui -size 300 300
curve_editor -input .\output\output07_edit.txt -curve_tessellation 4 -revolution_tessellation 10 -output .\output\vase_low.obj
curve_editor -input .\output\output07_edit.txt -curve_tessellation 10 -revolution_tessellation 60 -output .\output\vase_high.obj
raytracer -input .\input\scene07_vase_low.txt -gui -size 300 300
raytracer -input .\input\scene07_vase_high.txt -gui -size 300 300
curve_editor -input .\input\spline08_bezier_patch.txt -gui
curve_editor -input .\input\spline08_bezier_patch.txt -patch_tessellation 4 -output .\output\patch_low.obj
curve_editor -input .\input\spline08_bezier_patch.txt -patch_tessellation 10 -output .\output\patch_med.obj
curve_editor -input .\input\spline08_bezier_patch.txt -patch_tessellation 40 -output .\output\patch_high.obj
raytracer -input scene08_bezier_patch_low.txt -gui -size 300 300
raytracer -input scene08_bezier_patch_med.txt -gui -size 300 300
raytracer -input scene08_bezier_patch_high.txt -gui -size 300 300
curve_editor -input .\input\spline09_teapot.txt -curve_tessellation 4 -gui
curve_editor -input .\input\spline09_teapot.txt -patch_tessellation 4 -curve_tessellation 4 -revolution_tessellation 10 -output .\output\teapot_low.obj
curve_editor -input .\input\spline09_teapot.txt -patch_tessellation 30 -curve_tessellation 30 -revolution_tessellation 100 -output .\output\teapot_high.obj
raytracer -input .\input\scene09_teapot_low.txt -gui -size 300 300
raytracer -input .\input\scene09_teapot_high.txt -gui -size 300 300
curve_editor -input .\output\output07_edit.txt -curve_tessellation 20 -revolution_tessellation 100 -output vase_very_high.obj
raytracer -input .\input\scene10_transparent_vase.txt -output .\output\output10.tga -grid 30 30 30 -size 300 300 -bounces 4 -shade_back -jittered_samples 9 -tent_filter 1.0 -shadows
raytracer -input .\input\scene11_reflective_teapot.txt -output .\output\output11.tga -grid 50 30 30 -size 300 300 -bounces 4 -shade_back -jittered_samples 9 -tent_filter 1.0 -shadows