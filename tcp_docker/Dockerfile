FROM centos
ADD index.html /var/www/html/index.html
ADD start.sh /root/start.sh
RUN yum install -y httpd
ENTRYPOINT sh /root/start.sh
