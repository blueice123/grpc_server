FROM python:3.7.12

WORKDIR /usr/src/app
# RUN adduser myuser
# USER myuser
# WORKDIR /home/myuser

COPY ./grpc/ ./
RUN python -m pip install --upgrade pip
RUN python -m pip install grpcio
RUN python -m pip install grpcio-tools
RUN pip install --no-cache-dir -r ./requirements.txt

EXPOSE 50051
CMD [ "python", "./examples/python/helloworld/greeter_server.py" ]

