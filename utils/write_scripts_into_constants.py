from os import path
from glob import glob


script_constants_dir = "script_constants_python"
script_filenames = glob(path.join(script_constants_dir, "*.ps1"))

output_file_content = ""

for script_path in script_filenames:
    script_filename = path.basename(script_path).split(".")[0]
    with open(script_path) as f:
        content = "".join(f.readlines())
        content = content.replace("\\", "\\\\")
        output_file_content += f"{script_filename}_script = \"\"\"\n{content}\n\"\"\"\n"
    print(f"Read {script_path}")

output_file = path.join(script_constants_dir, "script_constants.py")
with open(output_file, "w+") as f:
    f.write(output_file_content)


script_constants_dir = "script_constants_c"
script_filenames = glob(path.join(script_constants_dir, "*.ps1"))

output_code_file_content = "#include \"script_constants.h\"\n\n"
output_header_file_content = ""

for script_path in script_filenames:
    script_filename = path.basename(script_path).split(".")[0]
    output_header_file_content += f"extern const char *{script_filename}_script;\n"
    with open(script_path) as f:
        output_code_file_content += f"const char *{script_filename}_script = \n"
        for line in f.readlines():
            line = line.rstrip().replace("\\", "\\\\").replace("\"", "\\\"")
            output_code_file_content += f"\"{line}\"\n"
        output_code_file_content += ";\n"
    print(f"Read {script_path}")

output_file = path.join(script_constants_dir, "script_constants.h")
with open(output_file, "w+") as f:
    f.write(output_header_file_content)
output_file = path.join(script_constants_dir, "script_constants.c")
with open(output_file, "w+") as f:
    f.write(output_code_file_content)


print("All files processed.")
