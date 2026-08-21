import re

with open("brilcalc.log", "r") as file:
	content = file.read()

pattern = r"\|\s*(\d+)\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|\s*(\d+)\s*\|\s*([\d.]+)\s*\|\s*([\d.]+)\s*\|"

matches = re.findall(pattern, content)

recorded_pb = float(matches[-1][5])
recorded_fb = recorded_pb / 1000

print(f"Luminosidade integrada recorded: {recorded_fb:.1f} fb^-1")
