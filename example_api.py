from fastapi import FastAPI
from pydantic import BaseModel

app = FastAPI()

class SensorData(BaseModel):
    device_id: str
    pm25: int

@app.post("/api/sensor")
async def receive(data: SensorData):
    print(data)
    return {"status": "ok"}
