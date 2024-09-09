from os import path
from glob import glob


script_constants_dir = "script_constants"
script_filenames = glob(path.join(script_constants_dir, "*.ps1"))

output_file_content = ""

for script_path in script_filenames:
    script_filename = path.basename(script_path).split(".")[0]
    with open(script_path) as f:
        content = "".join(f.readlines())
        content = content.replace("\\", "\\\\")
        output_file_content += f"{script_filename} = \"\"\"\n{content}\n\"\"\"\n"
    print(f"Read {script_filename}")

output_file = path.join(script_constants_dir, "script_constants.py")
with open(output_file, "w+") as f:
    f.write(output_file_content)

print("All files processed.")
