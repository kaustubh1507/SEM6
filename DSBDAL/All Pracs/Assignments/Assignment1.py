import pandas as pd
import numpy as np

df = pd.read_csv('../DSBDAL (Rohan Doshi)/datasets/nba.csv')
print(df)

print(df.isna().sum())