import unreal

r1 = unreal.Rotator(10.0, 20.0, 30.0)
unreal.log(f"Positional (10, 20, 30) -> pitch={r1.pitch}, yaw={r1.yaw}, roll={r1.roll}")

r2 = unreal.Rotator(pitch=10.0, yaw=20.0, roll=30.0)
unreal.log(f"Keyword (pitch=10, yaw=20, roll=30) -> pitch={r2.pitch}, yaw={r2.yaw}, roll={r2.roll}")
