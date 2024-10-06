#Given number of days, convert it in terms of Years, Week and Days.

given_days=30
years= int(given_days/365)
weeks = int((given_days%365)/7)
days = int((given_days%365)%7)

print(f"years :: {years} \nweeks::  {weeks} \ndays::  {days} \n ")