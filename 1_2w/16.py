import subprocess

source = "3task.cpp"
output = "./compiled.exe"

compile_result = subprocess.run(["g++", source, "-o", output], capture_output = True, text = True)

result_run = subprocess.run([output], capture_output = True, text = True)

print(result_run.stdout)