### gRPC 및 nginx를 통한 NLB의 TCP sticky session 테스트 결과 

#### 0. ISSUE: 
 - Client에서 Stciky되어서 특정 Pod로 데이터가 전송될 때 Pod가 죽을 경우 장시간 트래픽(10초~30초)이 다른 pod로 전환되지 않는 문제
   - [k8s 오브젝트 설정](k8s.yaml)
   - 해당 문제는 deployment에 의해 새롭게 뜨는 pod가 NLB에 register 완료되는 시점까지 계속 connection confused 되는듯 합니다.
 - Pod 삭제 직후 트래픽이 바로 전달되지 않는 문제
   - 위 문제와 동일
 - Pod 복구 직후 단시간 스티키 세션이 안걸리고 로드밸런싱 되는 문제
   - 아마도 NLB의 a존 노드와 c존 노드가 서로 다른 pod에 sticky를 걸고, client는 번갈아가면서 호출되면서 발생한 문제는 아닌지 의심됩니다. 

#### 1. 테스트 환경:
 - EKS 1.21
 - aws load balancer controller 2.2.4
 - NLB
   - [grpc](grpc.yaml)
   - [tcp](tcp.yaml)
 - TCP 환경
   - [Apache pod](tcp_docker/)
 - gRPC 환경
   - [Server](grpc_docker/grpc/examples/python/helloworld/server.py)
   - [Client](grpc_docker/grpc/examples/python/helloworld/nlb.py)


#### 2. 현재 구조에서의 NLB특징
 - Security group으로 방화벽 제어가 안됨.
 - pod가 죽을 때 session draining이 정상적으로 처리되지 않음 


#### 만약 statefulset으로 오브젝트를 정의할 경우 단점
 - Rolling 배포 전략과 partition을 통한 Canary 배포 전략만 구사할 수 있음 
