import requests
import urllib3


def main():
    urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

    urls = [
        "https://www.google.com",
        "https://www.facebook.com",
        "https://www.x.com",
        "https://www.github.com"
    ]
    for url in urls:
        resp = requests.get(url, verify=False)
        print(f"{url} returned {resp.status_code}")


if __name__ == "__main__":
    main()
