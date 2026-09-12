# AWS Notes

## MODULE 1: Defining Cloud Computing

### Cloud Deployment Types

**Cloud**
In a cloud-based deployment model, you have the flexibility to migrate your existing resources to the cloud, design and build new applications within the cloud environment, or use a combination of both.

For instance, a company might migrate data resources to the cloud, then develop an application comprised of virtual servers, databases, and networking components entirely hosted in the cloud.

**On-premises**
Deploying resources on premises using virtualization and resource management tools does not provide many of the benefits of cloud computing. However, it is sometimes sought for its ability to provide dedicated resources and low latency.

In most cases this deployment model is the same as legacy IT infrastructure while using application management and virtualization technologies to try increasing resource utilization.

**Hybrid**
In a hybrid deployment, cloud-based resources and on-premises infrastructure work together. This approach is ideal for situations where legacy applications must remain on premises due to maintenance preferences or regulatory requirements.

For instance, a company might choose to retain certain regulated legacy applications on-premises while using cloud services for advanced data processing and analytics.

Multi-cloud deployments can also be considered hybrid deployments.

### AWS Regions and Availability Zones

**AWS Regions**
AWS Regions are physical locations around the world that contain groups of data centers. These groups of data centers are called Availability Zones. Each AWS Region consists of a minimum of three physically separate Availability Zones within a geographic area.

**Availability Zones**
An Availability Zone consists of one or more data centers with redundant power, networking, and connectivity. Regions and Availability Zones are designed to provide low-latency, fault-tolerant access to services for users within a given area.

### Shared Responsibility Model

**Customer responsibilities**
Customers are responsible for managing security requirements for their data, including which data they store on AWS and who has access to that data. Customers also control how access to the data is granted, managed, and revoked.

Additionally, customers are responsible for client-side encryption.

**Shared responsibilities**
Depending on the service used, responsibilities might shift between the customer and AWS. Components such as server-side encryption, network traffic protection, platform and application management, and OS, network, and firewall configuration vary by service in terms of who is responsible for these items. As you learn more about different types of services, you will see specific examples of how these elements are divided between the customer and AWS.

**AWS responsibilities**
AWS is responsible for protecting the infrastructure that runs all of the services offered in the AWS Cloud. This infrastructure is composed of the hardware, software, networking, and facilities that run AWS Cloud services.

### Challenges of On-Premises Resources
Imagine that you're responsible for designing your company's infrastructure to support new websites. With traditional on-premises resources, you must purchase hardware upfront, wait for delivery, and handle installation and configuration. This process is time-consuming, costly, and inflexible because you're locked into a specific capacity that might not align with changing demands.

### Benefits of Using Cloud Resources
In contrast, with Amazon EC2, you can quickly launch, scale, and stop instances based on your needs without the delays and upfront costs associated with traditional on-premises resources.

---

## MODULE 2

### Amazon EC2
It offers on-demand compute capacity that can be quickly launched, scaled, and terminated, with costs based only on active usage.

### Ways to Access AWS Services

**AWS Management Console**
The AWS Management Console is a web interface for managing AWS services, offering quick access to services, search functionality, and simplified workflows. With the mobile app, you monitor resources, view alarms, and check billing, supporting multiple logged-in identities at once.

Good for: Users who prefer a visual, easy-to-use interface for managing and configuring AWS services

**AWS CLI**
With the AWS CLI, you manage multiple AWS services directly from the command line across Windows, macOS, and Linux. You can automate tasks through scripts, such as launching EC2 instances.

Good for: Advanced users and developers who need to automate tasks, script actions, and manage AWS resources efficiently from the command line

**AWS SDK**
The AWS SDK simplifies integrating AWS services into your applications by providing APIs for various programming languages. AWS offers documentation and sample code for languages like C++, Java, and .NET to help you get started.

Good for: Developers looking to integrate AWS services into their applications using language-specific APIs

### AWS Pricing Options

By understanding the different Amazon EC2 pricing options, you can make more informed decisions and optimize your costs based on your specific usage needs.

**On-Demand Instances**
Pay only for the compute capacity you consume with no upfront payments or long-term commitments required.

**Reserved Instances**
Get a savings of up to 75 percent by committing to a 1-year or 3-year term for predictable workloads using specific instance families and AWS Regions.

**Spot Instances**
Bid on spare compute capacity at up to 90 percent off the On-Demand price, with the flexibility to be interrupted when AWS reclaims the instance.

**Savings Plans**
Save up to 72 percent across a variety of instance types and services by committing to a consistent usage level for 1 or 3 years.

**Dedicated Hosts**
Reserve an entire physical server for your exclusive use. This option offers full control and is ideal for workloads with strict security or licensing needs.

**Dedicated Instances**
Pay for instances running on hardware dedicated solely to your account. This option provides isolation from other AWS customers.

### Scalability
Scalability refers to the ability of a system to handle an increased load by adding resources. You can scale up by adding more power to existing machines, or you can scale out by adding more machines. Scalability focuses on long-term capacity planning to make sure that the system can grow and accommodate more users or workloads as needed.

### Elasticity
Elasticity is the ability to automatically scale resources up or down in response to real-time demand. A system can then rapidly adjust its resources, scaling out during periods of high demand and scaling in when the demand decreases. Elasticity provides cost efficiency and optimal resource usage at any given moment.

### Amazon EC2 Auto Scaling
Amazon EC2 Auto Scaling automatically adjusts the number of EC2 instances based on changes in application demand, providing better availability. It offers two approaches. Dynamic scaling adjusts in real time to fluctuations in demand. Predictive scaling preemptively schedules the right number of instances based on anticipated demand.

### Elastic Load Balancing
Elastic Load Balancing (ELB) automatically distributes incoming application traffic across multiple resources, such as EC2 instances, to optimize performance and reliability. A load balancer serves as the single point of contact for all incoming web traffic to an Auto Scaling group. As the number of EC2 instances fluctuates in response to traffic demands, incoming requests are first directed to the load balancer. From there, the traffic is distributed evenly across the available instances.

Although ELB and Amazon EC2 Auto Scaling are distinct services, they work in tandem to enhance application performance and ensure high availability. Together, they enable applications running on Amazon EC2 to scale effectively while maintaining consistent performance.

### ELB Routing Methods
To optimize traffic distribution, ELB uses several routing methods: Round Robin, Least Connections, IP Hash, and Least Response Time. These routing strategies work together for efficient traffic management and optimal application performance.

**Round Robin**
Distributes traffic evenly across all available servers in a cyclic manner.

**Least Connections**
Routes traffic to the server with the fewest active connections, maintaining a balanced load.

**IP Hash**
Uses the client's IP address to consistently route traffic to the same server.

**Least Response Time**
Directs traffic to the server with the fastest response time, minimizing latency.

### Application Architecture

**Monolithic applications**
Applications consist of multiple components that work together to transmit data, fulfill requests, and keep the application running smoothly. In a traditional approach to application architecture, the components—such as database logic, web application servers, user interfaces, and business logic—are tightly coupled. This means that if one component fails, it can cause the failure of other components, potentially bringing down the entire application.

**Microservices architecture**
To improve application availability and resilience, you can adopt a microservices architecture. In this approach, application components are loosely coupled, meaning that if one component fails, the others continue to function normally. The communication between components remains intact, and the failure of a single component does not impact the entire system. This design promotes greater flexibility and reliability in the application.

### Amazon EventBridge
EventBridge is a serverless service that helps connect different parts of an application using events, helping to build scalable, event-driven systems. With EventBridge, you route events from sources like custom apps, AWS services, and third-party software to other applications. EventBridge simplifies the process of receiving, filtering, transforming, and delivering events, so you can quickly build reliable applications.

### Amazon SQS
Amazon SQS is a message queuing service that facilitates reliable communication between software components. It can send, store, and receive messages at any scale, making sure messages are not lost and that other services don't need to be available for processing. In Amazon SQS, an application places messages into a queue, and a user or service retrieves the message, processes it, and then removes it from the queue.

---

## MODULE 3

### Unmanaged and Managed Services

AWS offers both unmanaged and managed services to suit different levels of control and responsibility. By understanding this model, you will know which tasks AWS manages and which you are responsible for, helping you secure and manage your cloud resources effectively.

**Unmanaged and managed services**
With unmanaged compute services like Amazon EC2, AWS takes care of the underlying physical infrastructure, but you're responsible for setting up, securing, and maintaining the operating system, network configurations, and applications on your instances. Managed services, on the other hand, reduce the amount of infrastructure you need to manage. While AWS handles much of the operational overhead, you might still need to perform some provisioning or configuration depending on the service.

Using managed services shows a decrease in customer responsibility.

**Fully-managed services**
Fully-managed services—like serverless ones—take abstraction even further, eliminating the need to provision or manage any servers at all. The underlying infrastructure is fully managed by AWS, so you can focus entirely on writing and deploying code. Later in this module, you will explore Lambda. Lambda is a serverless compute service where AWS handles the infrastructure, scaling, and availability, while you remain responsible for securing and managing your application code.

### AWS Lambda
Lambda is a serverless compute service that runs code in response to events without the need to provision or manage servers. It automatically manages the underlying infrastructure, scaling resources based on the volume of requests. You are charged only for the compute time consumed, down to the millisecond. Lambda handles execution, scaling, and resource allocation. You can optimize performance by configuring the appropriate memory size for your function.

### Containers and VMs
A container packages your application with everything it needs to run, so it works the same on any computer. This helps to move, update, and manage. Containers are faster and lighter than virtual machines (VMs) because they share the host computer's operating system. VMs use a hypervisor to run full, separate operating systems, which makes them less resource-efficient and have longer startup times.

**Deployment consistency with containers**
When a developer's environment differs from staging or production, deployments can fail and become difficult to debug. Containers solve this by keeping the application's environment consistent everywhere, making deployments smoother and assisting troubleshooting.

**Scaling containers with orchestration**
As containerized applications scale, managing them becomes more complex. A setup that began with a few containers on a single host can quickly grow into hundreds or thousands of containers across multiple hosts. At that scale, manually handling container lifecycle, monitoring, and general operations becomes unsustainable. This is where orchestration tools come in. They automate deployment, scaling, and management to keep everything running smoothly.

### Amazon ECS
Amazon Elastic Container Service (Amazon ECS) is a scalable container orchestration service for running and managing containers on AWS, like Docker containers. Docker is a software platform for building, testing, and deploying applications quickly.

**Amazon ECS launch types**

Amazon ECS with Amazon EC2 is ideal for small-to-medium businesses that need full control over infrastructure. Suitable for custom applications requiring specific hardware or networking configurations, with the flexibility of Amazon EC2 and the simplicity of Amazon ECS.

Amazon ECS with AWS Fargate is perfect for startups or small teams building web applications with variable traffic. It's a serverless option—no server management required—so teams can focus on development while Amazon ECS handles scaling and orchestration.

---

## MODULE 4

### Amazon EKS
Amazon Elastic Kubernetes Service (Amazon EKS) is a fully managed service for running Kubernetes on AWS. It simplifies deploying, managing, and scaling containerized applications using open-source Kubernetes, with ongoing support and updates from the broader community.

**Amazon EKS launch types**

Amazon EKS with Amazon EC2: This is best for enterprises needing full control over infrastructure. It offers deep customization of EC2 instances alongside Kubernetes scalability—ideal for complex, large-scale workloads.

Amazon EKS with AWS Fargate: This is great for teams wanting Kubernetes flexibility without managing servers. It combines Kubernetes power with serverless simplicity, helping to scale applications quickly across various use cases.

### Amazon ECR
Amazon Elastic Container Registry (Amazon ECR) is where you can store, manage, and deploy container images. It supports container images that follow the Open Container Initiative (OCI) standards. You can push, pull, and manage images in your Amazon ECR repositories using standard container tooling and command line interfaces (CLIs).

### AWS Fargate
AWS Fargate is a serverless compute engine for containers. It works with both Amazon ECS and Amazon EKS. Fargate is a container hosting platform, unlike Amazon ECS and Amazon EKS, which are both container orchestration services.

When using Fargate, you do not need to provision or manage servers. Fargate manages your server infrastructure for you. You can focus more on innovating and developing your applications, and you pay only for the resources that are required to run your containers.

### AWS Elastic Beanstalk
Elastic Beanstalk is a fully managed service that streamlines the deployment, management, and scaling of web applications. Developers can upload their code, and Elastic Beanstalk automatically handles the provisioning of infrastructure, scaling, load balancing, and application health monitoring. It supports various programming languages and frameworks, such as Java, .NET, Python, Node.js, Docker, and more. It provides full control over the underlying AWS resources while automating many operational tasks.

Good for: Deploying and managing web applications, RESTful APIs, mobile backend services, and microservices architectures, with automated scaling and simplified infrastructure management

### AWS Batch
AWS Batch is a fully managed service that you can use to run batch computing workloads on AWS. It automatically schedules, manages, and scales compute resources for batch jobs, optimizing resource allocation based on job requirements.

Good for: Processing large-scale, parallel workloads in areas like scientific computing, financial risk analysis, media transcoding, big data processing, machine learning training, and genomics research

### Amazon Lightsail
Amazon Lightsail is a cloud service offering virtual private servers (VPSs), storage, databases, and networking at a predictable monthly price. It's ideal for small businesses, basic workloads, and developers seeking a straightforward AWS experience without the complexity of the full AWS Management Console.

Good for: Basic web applications, low-traffic websites, development and testing environments, small business websites, blogs, and learning cloud services

### AWS Outposts
AWS Outposts is a fully managed hybrid cloud solution that extends AWS infrastructure and services to on-premises data centers. It provides a consistent experience between on premises and the AWS Cloud, offering compute, storage, and networking components.

Good for: Low-latency applications, data processing in remote locations, migrating and modernizing legacy applications, and meeting regulatory compliance or data residency requirements

---

## MODULE 5

### Amazon Virtual Private Cloud (Amazon VPC)
An Amazon VPC lets you provision a logically isolated section of the AWS Cloud where you can launch AWS resources in a virtual network that you define.

**Subnet**
Subnets are used to organize your resources and can be made publicly or privately accessible. A private subnet is commonly used to contain resources like a database storing customer or transactional information. A public subnet is commonly used for resources like a customer-facing website.

A subnet is a section of a VPC in which you can group resources based on security or operational needs. Subnets can be public or private.

Public subnets contain resources that need to be accessible by the public, such as an online store's website.

Private subnets contain resources that should be accessible only through your private network, such as a database that contains customers' personal information and order histories.

### Virtual Private Gateways
What if you have a VPC that includes only private resources? You can think of the internet as the road between your home and the coffee shop. It is open and accessible to anyone. You want a way to protect the traffic you send on the internet from the public, internet service providers, and others who might be trying to track or intercept it. This is where a virtual private network (VPN) connection comes in.

VPN creates a connection that is more like a secure tunnel through the internet. Using encryption, it hides and protects everything you send and receive from outside eyes. A virtual private gateway is the component in the AWS Cloud that makes it possible for you to connect this protected traffic to enter the VPC. With a VPN connection, your data travels privately and safely, hidden from others using the same route.

With a virtual private gateway, you can establish a VPN connection between your VPC and a private network, such as an on-premises data center or internal corporate network. A virtual private gateway allows traffic into the VPC only if it is coming from an approved network.

### AWS Client VPN
AWS Client VPN is a networking service you can use to connect your remote workers and on-premises networks to the cloud. It is a fully managed, elastic VPN service that automatically scales up or down based on user demand. Because it is a cloud VPN solution, you don't need to install and manage hardware or try to estimate how many remote users to support at one time.

Benefits: AWS Client VPN provides advanced authentication, remote access. It is elastic and fully managed.

Use case: It can be used to quickly scale remote-worker access.

### AWS Site-to-Site VPN
Site-to-Site VPN creates a secure connection between your data center or branch offices and your AWS Cloud resources.

Benefits: Site-to-Site VPN provides high availability, secure and private sessions, and accelerates applications.

Use cases: It can be used for application migration and secure communication between remote locations.

### AWS PrivateLink
AWS PrivateLink is a highly available, scalable technology that you can use to privately connect your VPC to services and resources as if they were in your VPC. You do not need to use an internet gateway, NAT device, public IP address, Direct Connect connection, or AWS Site-to-Site VPN connection to allow communication with AWS services or resources from your private subnets. Instead, you control the specific API endpoints, sites, services, and resources that are reachable from your VPC.

Benefits: AWS PrivateLink helps you secure your traffic and connect with simplified management rules.

Use case: It is used for connecting your clients in your VPC to resources, other VPCs, and endpoints.

### AWS Direct Connect
Direct Connect is a service that makes it possible for you to establish a dedicated private connection between your network and VPC in the AWS Cloud.

Benefits: AWS Direct Connect reduces network costs and increases amount of bandwidth.

### Network ACLs

**Virtual firewall controlling traffic**
A network ACL is a virtual firewall that controls inbound and outbound traffic at the subnet level.

For example, imagine that you are at the airport. Travelers are trying to enter into a different country. You can think of the travelers as packets and the passport control officer as a network ACL. The passport control officer checks travelers' credentials when they are both entering and exiting the country. This is similar to how a network ACL checks permissions every time a packet travels across a subnet boundary.

Each AWS account includes a default network ACL. When configuring your VPC, you can use your account's default network ACL or create custom network ACLs. By default, your account's default network ACL allows all inbound and outbound traffic, but you can modify it by adding your own rules.

For custom network ACLs, all inbound and outbound traffic is denied until you add rules to specify which traffic to allow. Additionally, all network ACLs have an explicit deny rule. This rule makes sure that if a packet doesn't match any of the other rules on the list, the packet is denied.

**Stateless packet filtering**
Network ACLs perform stateless packet filtering. They remember nothing and check packets that cross the subnet border each way: inbound and outbound.

Recall the previous example of a traveler who wants to enter into a different country. This is similar to sending a request out from an Amazon EC2 instance and to the internet.

When a packet response for that request comes back to the subnet, the network ACL does not remember your previous request. The network ACL checks the packet response against its list of rules to determine whether to allow or deny.

### Security Groups

**Control inbound and outbound traffic at the resource level**
After a packet has entered a subnet, it must have its permissions evaluated for resources within the subnet, such as Amazon EC2 instances. A security group is the VPC component that checks packet permissions for an Amazon EC2 instance. It is a virtual firewall that controls inbound and outbound traffic for specific AWS resources, like Amazon EC2 instances.

By default, a security group denies all inbound traffic and allows all outbound traffic. For this example, suppose that you are at an apartment building with a door attendant who greets guests at the door. You can think of the guests as packets and the door attendant as a security group. With the default settings, the security groups won't let anyone in and allows all outbound traffic out.

With security groups, you can add custom rules to configure which traffic should be allowed. Any other traffic would then be denied. For example, custom rules can be given separately for inbound and outbound traffic. As guests arrive, the door attendant checks a list to make sure they can enter the building. However, the door attendant does not check the list again when guests are exiting the building.

Note: If you have multiple Amazon EC2 instances within the same VPC, you can associate them with the same security group or use different security groups for each instance.

**Stateful packet filtering**
Security groups perform stateful packet filtering. They remember previous decisions made for incoming packets.

Consider the same example of sending a request out from an Amazon EC2 instance to the internet. When a packet response for that request returns to the instance, the security group remembers your previous request. The security group allows the response to proceed, regardless of inbound security group rules.

---

## MODULE 6

### Amazon Elastic Block Store (EBS)
Amazon EBS provides persistent block-level storage volumes for use with Amazon EC2 instances. EBS volumes act like external hard drives, offering consistent and low-latency performance for workloads like databases and file systems.

EBS volumes can be conveniently backed up, resized, and attached to different EC2 instances. To create an EBS volume, you define the configuration for things like volume size and type. After the volume has been created, it can be attached to an Amazon EC2 instance. Because EBS volumes are for data that needs to persist, it's important to back up the data. It's recommended that you take incremental backups of EBS volumes by creating Amazon EBS snapshots.

**EBS Snapshots**
EBS snapshots are point-in-time backups of EBS volume. They can be used for disaster recovery, data migration, volume resizing, and for creating consistent backups of production workloads. EBS snapshots are incremental, so they only save the blocks on the volume that have changed after your most recent snapshot.

EBS snapshots can be used to create multiple new volumes, and new volumes created from a snapshot are an exact copy of the original volume at the time the snapshot was taken. Snapshots of EBS volumes are stored redundantly in multiple Availability Zones using Amazon S3.

**Amazon Data Lifecycle Manager**
You can automate the creation, retention, and deletion of EBS snapshots using Amazon Data Lifecycle Manager. Amazon Data Lifecycle Manager can schedule snapshots during off-peak hours to minimize performance impact and automatically delete outdated backups to control storage costs. It's particularly valuable for large-scale deployments where manual snapshot management would be time-consuming and error-prone.

### Amazon Simple Storage Service (S3)
Amazon S3 is a fully managed, highly-available object storage service for storing and retrieving any amount of data as objects. It offers 99.999999999 percent durability, meaning your data is highly protected against loss, and offers features like versioning, lifecycle management, and various storage classes to optimize costs.

Amazon S3 stores files as objects in containers known as buckets, and each object can range in size from a few bytes to several terabytes. It integrates seamlessly with other AWS services and supports a wide range of use cases, from basic backups to complex data lakes.

**S3 objects**
An object in Amazon S3 is the fundamental unit of data storage. When you upload a file to Amazon S3, it becomes an object and is stored durably across multiple facilities within your chosen Region.

Each object typically includes the data itself, metadata, and a unique identifier, or key. Objects can be of any file type, such as images, videos, documents, or application data, and can range in size from a few bytes to several terabytes.

Each Amazon S3 object is uniquely identified within a bucket by its key, which is essentially its file name. Objects also have properties like version ID, access control information, and user-defined metadata.

**S3 buckets**
An S3 bucket is a container for storing objects in Amazon S3. Buckets have a globally unique name across all of AWS, which helps to identify and organize your stored data.

Buckets serve as the basic unit for access control and can hold a virtually unlimited number of objects. They play a crucial role in data management by making it possible to group related objects and apply policies at the bucket level.

When creating a bucket, you specify its name and the Region where it will reside. Buckets can be configured with various settings, including versioning, logging, and access permissions.

**S3 bucket policies vs. identity-based policies**
Amazon S3 bucket policies are resource-based policies that can only be attached to S3 buckets. An S3 bucket policy specifies which actions are allowed or denied on the bucket, in addition to every object in that bucket.

Permissions that control what actions users, groups, or roles can perform on S3 resources are configured using identity-based policies. These policies attach directly to identities rather than to the S3 resources themselves. You can use these policies to specify which S3 buckets and objects users can access and what actions they can perform.

**S3 encryption**
Amazon S3 provides encryption capabilities to protect data both at rest and in transit. These encryption features help maintain data confidentiality and comply with various security standards and regulations. These capabilities are as follows:

Encryption at rest secures data stored in S3 buckets, preventing unauthorized access to stored objects.

Encryption in transit safeguards data traveling to and from Amazon S3, maintaining secure communication between clients and the service.

### S3 Storage Classes

**S3 Standard**
S3 Standard is considered general-purpose storage for cloud applications, dynamic websites, content distribution, mobile and gaming applications, and big data analytics. When you upload an object to Amazon S3 without specifying a storage class, the object is added to S3 Standard by default.

**S3 Intelligent-Tiering**
This tier is useful if your data has unknown or changing access patterns. S3 Intelligent-Tiering stores objects in three tiers: a frequent access tier, an infrequent access tier, and an archive instant access tier. Amazon S3 monitors access patterns of your data and automatically moves your data to the most cost-effective storage tier based on frequency of access.

**S3 Standard Infrequent Access (Standard-IA)**
S3 Standard-Infrequent Access (S3 Standard-IA) is for data that is accessed less frequently but requires rapid access when needed. S3 Standard-IA offers the high durability, high throughput, and low latency of S3 Standard, with a low per-GiB storage price and per-GiB retrieval fee. This storage tier is ideal if you want to store long-term backups, disaster recovery files, and so on.

**S3 One Zone Infrequent Access (One Zone-IA)**
S3 One Zone-Infrequent Access (S3 One Zone-IA) stores data in a single Availability Zone, reducing costs compared to S3 Standard-IA, which uses three zones. This storage class suits customers seeking affordable storage for infrequently accessed data without high availability needs. It's perfect for storing secondary backups or easily recreatable data.

**S3 Express One Zone**
S3 Express One Zone stores data in a single Availability Zone. It was purpose-built to deliver consistent single-digit millisecond data access for your most frequently accessed data and latency-sensitive applications. S3 Express One Zone delivers data access speed up to 10x faster and request costs up to 80% lower than S3 Standard.

**S3 Glacier Instant Retrieval**
Use S3 Glacier Instant Retrieval for archiving data that is rarely accessed and requires millisecond retrieval. Data stored in this storage class offers a cost savings of up to 68 percent compared to the S3 Standard-IA storage class, with the same latency and throughput performance.

**S3 Glacier Flexible Retrieval**
S3 Glacier Flexible Retrieval offers low-cost storage for archived data that is accessed 1–2 times per year. With S3 Glacier Flexible Retrieval, your data can be accessed in as little as 1–5 minutes using an expedited retrieval. You can also request bulk retrievals in up to 5–12 hours at no additional cost. It's an ideal solution for backup, disaster recovery, offsite data storage needs, and for when some data occasionally must be retrieved in minutes.

**S3 Glacier Deep Archive**
S3 Glacier Deep Archive is the lowest-cost Amazon S3 storage class. It supports long-term retention and digital preservation for data that might be accessed once or twice per year. Data stored in the S3 Glacier Deep Archive storage class has a default retrieval time of 12 hours. It is designed for customers that retain data sets for 7–10 years or longer, to meet regulatory compliance requirements. Examples include those in highly regulated industries, such as financial services, healthcare, and public sectors.

**S3 Outposts**
Amazon S3 Outposts delivers object storage to your on-premises AWS Outposts environment using Amazon S3 APIs and features, and serves workloads with local data residency requirements. It also helps maintain optimal performance when data must remain in close proximity to on-premises applications.

### Amazon Elastic File System (EFS)
Amazon EFS is a fully managed, scalable file storage service for use with AWS cloud services and on-premises resources. It operates using the Linux Network File System (NFS) protocol, and automatically scales to petabytes as you add or remove files without disrupting applications. EFS is designed to support a wide variety of workloads and can be accessed by multiple EC2 instances simultaneously.

### Amazon FSx
Amazon FSx makes it convenient and cost effective to launch, run, and scale feature-rich, high-performance file systems in the cloud. It supports a wide range of workloads with its reliability, security, scalability, and broad set of capabilities. Compared to Amazon EFS, which focuses on the Network File System (NFS) compatibility, Amazon FSx supports multiple filesystem protocols, including Windows File Server, Lustre, OpenZFS, and NetAPP ONTAP.

### AWS Storage Gateway
Storage Gateway is a hybrid cloud storage service that makes it possible to seamlessly integrate on-premises environments with AWS Cloud storage. You can use it to extend your local storage to the cloud while maintaining low-latency access to frequently used data.

You can use Storage Gateway to streamline storage management and reduce costs for practical hybrid cloud storage use cases. These include moving backups to the cloud, using on-premises file shares backed by cloud storage, and providing low-latency access to data in AWS for on-premises applications.

---

## MODULE 7

### Amazon Aurora
Aurora is a managed relational database designed to help reduce unnecessary I/O operations. It's compatible with MySQL and PostgreSQL, provides high performance and availability, and automatically scales alongside your workloads. Aurora replicates data across multiple Availability Zones for enhanced durability and fault tolerance, and features automated backups, encryption at rest, and continuous monitoring.

### Amazon DynamoDB
DynamoDB is a fully managed NoSQL database service that provides fast and predictable performance for both document and key-value data structures. It's a powerful and incredibly fast database option for use cases that require a flexible schema, and is ideal for applications that require high performance and seamless scaling.

DynamoDB seamlessly scales alongside your data without impacting performance, which means that you only pay for the resources that you use. It also includes built-in security features for enhanced protection, and automatically spreads your data across multiple servers to handle your workload.

### Amazon ElastiCache
ElastiCache is a fully managed in-memory caching service that was built to help reduce the complexity of administering in-memory caching systems. This means that you can continue to use the same Redis, Valkey, or Memcached tools and configurations to scale your workloads. It automatically detects and replaces failed nodes, which makes it ideal for applications that need consistent high performance.

**Use cases:** Session data management, database query enhancement, and gaming leaderboards

### Amazon DocumentDB
Amazon DocumentDB (with MongoDB compatibility) is fully managed service designed to handle semistructured data, which is information that doesn't conform to rigid relational schemas. Amazon DocumentDB is a MongoDB-compatible database, so it manages JSON-like documents with dynamic schemas.

Amazon DocumentDB is perfect for applications requiring frequent schema changes and document-oriented data. Unlike relational databases or nonrelational databases, you can quickly iterate without relying on predefined schemas. Amazon DocumentDB can store, query, and index JSON data effortlessly, all while benefiting from automatic scaling, continuous backup, and enterprise-grade security features.

### Amazon Neptune
Neptune is a fully managed, purpose-built graph database service that manages highly connected data sets, like those used in social networking applications. It excels at understanding complex relationships that are difficult to identify in traditional relational databases like user connections, friend networks, and interaction patterns. Neptune can maintain high performance even as data complexity grows, and offers high availability with automatic failover and backups.

---

## MODULE 8

### AI/ML Services

**Amazon Comprehend**
Amazon Comprehend uses natural language processing to extract key insights from documents. It develops these insights by recognizing key phrases, language, sentiment, and other common elements in documents.

Use cases: Content classification, customer sentiment analysis, and compliance monitoring

**Amazon Polly**
Amazon Polly converts text into lifelike speech. It supports multiple languages, different genders, and a variety of accents.

Use cases: Virtual assistants, e-learning applications, and accessibility enhancements for visually impaired users

**Amazon Transcribe**
Amazon Transcribe converts speech into text. It supports multiple languages and offers features such as speaker identification, custom vocabulary, and real-time transcription.

Use Cases: Customer call transcription, automated subtitling, and metadata generation for media content

**Amazon Translate**
Amazon Translate is a text translation service. This service is ideal for global communication because it supports real-time and batch text translation across multiple languages.

Use cases: Document translation and multi-language application integrations

**Amazon Kendra**
Amazon Kendra uses natural language processing to search for answers within large amounts of enterprise content. Because it understands the context of a query, it can return more precise and relevant answers than just a list of documents with matching keywords.

Use cases: Intelligent search, chatbots, and application search integration

**Amazon Rekognition**
Amazon Rekognition is a video analysis service. It can identify objects, people, text, scenes, and activities within images and videos stored in Amazon Simple Storage Service (Amazon S3).

Use cases: Content moderation, identity verification, media analysis, and home automation experiences

**Amazon Textract**
Amazon Textract detects and extracts typed and handwritten text found in documents, forms, and even tables within documents.

Use cases: Financial, healthcare, and government form text extraction for quick processing

**Amazon Lex**
With Amazon Lex, you can add voice and text conversational interfaces to your applications. This service uses both natural language understanding (NLU) and automatic speech recognition (ASR) to create lifelike conversations.

Use cases: Virtual assistants, natural language search for FAQs, and automated application bots

**Amazon Personalize**
With Amazon Personalize, you can use historical data to build intelligent applications with personalized recommendations for your customers.

Use cases: Personalized streaming, product, and trending recommendations

**Amazon SageMaker JumpStart**
SageMaker JumpStart is a machine learning hub within SageMaker AI that accelerates the process of building, training, and deploying ML models. SageMaker JumpStart offers a library of pre-built ML solutions across various domains such as computer vision, NLP, and tabular data. These pre-trained models can be fine-tuned to suit your specific needs and deployed with just a few clicks.

**Amazon Bedrock**
Amazon Bedrock is a fully managed service that was specifically designed for working with large foundation models and building generative AI applications. It provides access to FMs from Amazon and leading AI startups, such as Claude and Stable Diffusion, all through a single unified API. With Amazon Bedrock, you can quickly experiment with FMs, fine-tune them with your own data, and seamlessly integrate them into your AWS applications.

**Amazon Q Business**
Amazon Q Business can answer pressing questions, help solve problems, and take actions using the data and expertise found in your company's information repositories. Amazon Q Business provides this tailored assistance with a secure connection to commonly used systems.

Use cases: Information requests, automated workflows, and insight extraction

**Amazon Q Developer**
Amazon Q Developer provides code recommendations to accelerate development for coding languages including C#, Java, JavaScript, Python, and TypeScript applications. It integrates with multiple IDEs and helps developers write code faster by generating entire functions and logical blocks of code.

Use cases: Faster code generation, improved reliability and security, and automated code reviews

### Data Pipelines for ETL Processes
Both AI/ML and traditional data analytics need clean and accessible data in a format that's usable by analytics tools and AI algorithms. ETL processes are used for this purpose. With ETL, you perform the following steps:

Extract the data from various sources and store it.

Transform it into a consistent, usable format for downstream tools to consume.

Load it into a destination system, like a data warehouse or analytics platform.

Data pipelines are automated assembly lines used to make the ETL process efficient and repeatable. AWS has a suite of integrated services so you can build your own data pipelines.

**Amazon Kinesis Data Streams**
You can use Kinesis Data Streams for real-time ingestion of terabytes of data from applications, streams, and sensors. This serverless service even provides automatic provisioning and scaling in on-demand mode.

**Amazon Data Firehose**
Firehose is an option for data ingestion in near real-time. This fully managed service provides automatic provisioning and scaling. It also delivers data within seconds to data lakes, warehouses, and analytics services.

**Amazon Athena**
With Athena, you can run SQL queries to analyze data in relational, nonrelational, object, and custom data sources. This fully managed serverless service can access data hosted on Amazon S3, on premises, or even in multi-cloud environments. It offers a cost-effective solution for data analysis because you only pay for the queries you run.

**Amazon Redshift**
Amazon Redshift is a fully managed data warehouse solution. Its columnar storage and massively parallel processing architecture make it ideal for analyzing large datasets. You can use it to perform complex SQL queries on large datasets for frequent, high-performance analytical workloads.

**Amazon QuickSight**
With QuickSight, both technical and non-technical users can quickly create modern interactive dashboards and reports from various data sources without managing infrastructure. Amazon Q in QuickSight provides natural language queries so business analysts and users can build, discover, and share meaningful insights in seconds.

**Amazon OpenSearch Service**
With OpenSearch Service, you can search for relevant content through precise keyword matching or natural language queries. Unified dashboards provide real-time data visualization as you analyze and monitor logs, traces, and metrics for various applications.

---

## MODULE 9

### Authentication and Authorization

**Authentication** is the process of verifying the identity of a user or entity through credentials like a username and password combination.

Use case: An employee logs in to an employee portal.

**Authorization** grants users certain access rights and permissions that determine which actions they can perform in a system or application.

Use case: An employee can only access their own employee records inside the employee portal.

### AWS Identity and Access Management (IAM)
Securely manage identities and access to AWS services and resources.

One of the best ways to prevent security incidents before they happen is through proper permission and access management. With IAM, by default, all actions are denied. You must explicitly grant permission to someone before they can perform any actions in your account.

When you grant permissions, you should provide access only on a need-to-have basis. This concept is called the principle of least privilege.

The principle of least privilege dictates that you should only give people and systems access to what they need and nothing else.

IAM provides users, groups, and roles so you can configure access based on your company's specific operational and security needs. IAM policies define the needed access for these identities.

### AWS IAM Identity Center
IAM Identity Center centralizes identity and access management across AWS accounts and applications. IAM Identity Center can also connect to an existing identity source and provide your workforce with single sign-on access to all your connected AWS services and accounts. This is called federated identity management.

Federated identity management is a system that allows users to access multiple applications, services, or domains using a single set of credentials.

### AWS Secrets Manager
Secrets Manager provides a secure way to manage, rotate, and retrieve database credentials, API keys, and other secrets throughout their lifecycle. This helps keep your applications, services, and IT resources safe.

Secrets are confidential or private information intended to be known only to specific individuals or groups. Examples include passwords, database credentials, and API keys.

### AWS Systems Manager
Systems Manager provides a centralized view of nodes across your organization's accounts and Regions and multi-cloud and hybrid environments. With this service, you can quickly access node information, such as ID and operating system details, and automate registry edits, user management, and security patching.

Nodes are connection points in a network, system, or structure.

### Network and Application Attacks

Network and application protection is another vital component of a secure environment on AWS.

**DoS attacks**
In a denial of service attack, an attacker floods a web application with excessive network traffic. Legitimate customer requests are denied if the web application becomes overloaded and can no longer respond.

**DDoS attacks**
In a distributed denial of service (DDoS) attack, an attacker can use multiple infected computers (called zombie bots) to unknowingly send excessive traffic to a web application.

### AWS Shield
AWS Shield Standard is designed to automatically protect AWS customers from the most common, frequently occurring types of DDoS attacks at no cost. It uses a variety of analysis techniques to detect and mitigate incoming malicious network traffic in real time.

AWS Shield Advanced is a paid service that provides detailed attack diagnostics and the ability to detect and mitigate sophisticated DDoS attacks. It also integrates with other services, such as Amazon CloudFront, Amazon Route 53, and ELB.

Additionally, you can integrate AWS Shield with AWS WAF by writing custom rules to mitigate complex DDoS attacks.

### AWS WAF
AWS WAF is a web application firewall that monitors network requests that come into your web applications. When a request comes into AWS WAF, it checks the IP address against a web access control list (web ACL). If the request comes from a blocked IP address on the web ACL, AWS WAF denies access. Legitimate requests are allowed access.

### Data Encryption

Encryption is a key component of data protection.

**Encryption basics**
Data encryption works like a lock and key mechanism. If you have the right key, you can access the encrypted data. Otherwise, you cannot access the data. For example, let's say you are protecting a customer's profile. An encryption key is used to turn the profile information into a randomized set of characters. A decryption key is used to access the customer's information, such as their name, only when it's needed by your application.

**Types of data encryption**
Data encryption comes in the following two forms:

Data encryption at rest: The data is idle and not moving, like when it's stored in a database.

Data encryption in transit: The data is moving between locations, like when it's being sent from a database to an application. SSL/TLS certificates are used to establish encrypted network connections from one system to another.

### AWS Data Protection Services

**AWS Key Management Service (AWS KMS)**
You can use AWS KMS to create and manage cryptographic keys. These keys can then be used to encrypt and decrypt your data. You can also control the use of keys across a wide range of services and in your applications. For example, you can specify which IAM users and roles can manage keys. Your keys never leave AWS KMS, and you can temporarily disable them so they can no longer be used.

A cryptographic key is a random string of digits used for locking (encrypting) and unlocking (decrypting) data.

**Amazon Macie**
With Amazon Macie, you can monitor your sensitive data at rest to make sure it's safe. Macie uses machine learning (ML) and automation to discover sensitive data stored in Amazon S3. You can use Macie to assess your security posture, which is especially helpful for meeting compliance requirements.

**AWS Certificate Manager (ACM)**
ACM centralizes the management of your SSL/TLS certificates that provide data encryption in transit. It can be used to protect various AWS services and your connected on-premises resources.

SSL/TLS certificates are used to establish encrypted network connections from one system to another.

**Amazon Inspector**
Amazon Inspector helps improve the security and compliance of applications by running automated security assessments for Amazon EC2 instances, containers, and Lambda functions. It checks applications for security vulnerabilities and deviations from security best practices, such as open access to EC2 instances and installations of vulnerable software versions.

You can view completed assessments in the Amazon Inspector console. These assessments include a list of security findings prioritized by severity level. Each identified security issue includes a detailed description and a recommendation for how to fix it. You can also retrieve these findings through an API.

**Amazon GuardDuty**
Amazon GuardDuty provides intelligent threat detection across your infrastructure and resources. GuardDuty identifies threats by continuously monitoring streams of your account metadata and network activity in your environment. It uses known malicious IP addresses, anomaly detection, and machine learning to identify threats more accurately.

You can review detailed findings about any GuardDuty detected threats in the AWS Management Console. Findings include recommended steps for remediation. You can also configure AWS Lambda functions to perform remediation steps automatically.

**Amazon Detective**
After a threat has been detected, you can use Amazon Detective to further investigate the root cause. Detective helps you analyze threats with interactive visualizations contained in a unified AWS Management Console view. These visualizations include resource and user interactions over a configurable timeline with recommended steps for remediation.

**AWS Security Hub**
Security Hub brings multiple security services together into a single place and format. With this service, you can quickly see your security and compliance state in one comprehensive view. Security Hub automatically aggregates security findings from AWS and partner services and organizes them into actionable, meaningful groupings called insights. It can accelerate time to resolution (TTR) with automated remediation.

---

## MODULE 10

### Importance of Monitoring
Monitoring your cloud resources is important. It provides a way for you to continuously observe and analyze system activity, network traffic, and security events to detect potential threats or anomalies. Monitoring and observability are critical components for ensuring the security, availability, reliability, and performance of your cloud-based workloads and data.

Monitoring is performed using real-time monitoring tools, log collection and analysis, and dashboards.

### Amazon CloudWatch
CloudWatch monitors your AWS resources and the applications that you run on AWS in real time. With CloudWatch, you gain system-wide visibility into resource utilization, application performance, and operational health. CloudWatch does more than just monitor. It has several features that work together:

CloudWatch metrics

CloudWatch alarms

CloudWatch dashboards

CloudWatch logs

### AWS CloudTrail
CloudTrail tracks user activity and API usage in the AWS Cloud, on premises, and even with other cloud providers. CloudTrail provides a detailed history of API calls, so you can track changes and identify who made them and when. This helps you understand what actions were taken on your AWS resources.

Benefits: CloudTrail provides auditing, security monitoring, and operational troubleshooting. It also helps you prove compliance and improve your security posture.

Use cases: It can be used for compliance and auditing, identifying security incidents, troubleshooting operational issues.

### AWS Compliance
The AWS Compliance portal contains resources to help you learn more about AWS compliance. You can read customer compliance stories to discover how companies in regulated industries have solved various compliance, governance, and audit challenges.

You can also access compliance whitepapers and documentation on topics such as the following:

AWS answers to key compliance questions

An overview of AWS risk and compliance

An auditing security checklist

### AWS Organizations
Organizations helps you centrally manage and govern your environment as you grow and scale your AWS resources. It helps you manage policies for groups of accounts and automate account creation.

Benefits: Organizations provides several benefits like quickly scaling your environment by programmatically creating new AWS accounts for resources and teams. It also helps by simplifying permission management through SCPs and managing and optimizing costs across your AWS accounts and resources.

Use cases: It can be used for automating AWS account creation, providing tools and access for your security teams, controlling user access to designated services, and sharing common resources across accounts.

**Management account**
The management account is the central AWS account that creates and manages the organization. It's responsible for overall control and governance.

**Service control policies (SCP)**
An SCP is a policy that lets you place restrictions on the AWS services, resources, and individual API actions that users and roles in each account can access. SCPs can be applied to either OUs or individual member accounts.

**Member account not in an OU**
If you have a member account that has unique requirements that do not overlap with those of an organizational unit, you can add them to the organization. They do not have to be placed under an OU. This account can still take advantage of benefits such as consolidated billing.

**Organizational unit (OU)**
An organizational unit (OU) is a logical grouping of accounts in an AWS Organization. OUs can contain member accounts or nested OUs.

### AWS Control Tower
AWS Control Tower is a service you can use to enforce and manage governance rules for security, operations, and compliance at scale across all your organizations and accounts in the AWS Cloud.

Benefits: AWS Control Tower can help you save time while providing governance. It uses preconfigured controls, which can help you to quickly set up multi-account environments, automation with built-in governance, and integration of third-party software at scale.

Use cases: Use AWS Control Tower to quickly deploy applications and provision compliant AWS accounts.

### AWS Health Dashboard
With AWS Health Dashboard, you can view account-specific health information and get AWS Health event updates. You can also use AWS Health programmatically using the AWS Health API, which is available with AWS Premium Support.

Benefits: AWS Health Dashboard provides valuable information as a data source for events and changes. It gives you timely and actionable guidance to remedy issues. It also helps manage service health and is integrated and automated to use at scale.

Use cases: Use AWS Health Dashboard to view account-specific health information. You can also use it to plan for lifecycle events or troubleshoot an incident.

### Trusted Advisor
Optimizing large scale cloud deployments is extremely important to do, and it's not a one-time thing. You must look for ways to optimize for costs, performance, security, and resilience. With AWS Trusted Advisor, you can continuously evaluate your AWS environment by using best practice checks across several categories. All AWS Support plans include access to dozens of Trusted Advisor checks. With Business Support and other advanced plans, you can benefit from hundreds of checks.

Benefits: Trusted Advisor helps you align with AWS best practices, prioritize recommendations, and optimize your AWS resources at scale.

Use cases: It can be used to optimize cost, efficiency, security, improve performance, and track service limits.

---

## AWS Service Reference Table

| Service | Description |
|---|---|
| Amazon EC2 | Runs virtual servers in the cloud with flexible computing capacity. |
| Amazon EC2 Auto Scaling | Automatically adjusts instance count based on demand for high availability and cost-efficiency. |
| Elastic Load Balancing | Automatically distributes incoming application traffic across multiple EC2 instances for high availability and fault tolerance. |
| Amazon Simple Notification Service (SNS) | Messaging service for sending notifications to users or applications through SMS, email, or mobile push notifications. |
| Amazon Simple Queue Service (SQS) | Decouples application components through message queuing, storing and processing messages reliably. |
| Amazon Elastic Container Registry (ECR) | Fully managed service for storing, managing, and deploying container images securely at scale. |
| Amazon Elastic Container Service (ECS) | Fully managed service that streamlines the deployment, management, and scaling of containerized applications. |
| Amazon Elastic Kubernetes Service (EKS) | Fully managed Kubernetes service that streamlines running Kubernetes clusters on AWS and on premises. |
| AWS Fargate | Serverless compute engine for running containers without managing servers; integrates with ECS and EKS. |
| AWS Elastic Beanstalk | Fully managed service for deploying and scaling web applications without managing infrastructure. |
| AWS Batch | Fully managed service for efficiently running large-scale batch computing jobs. |
| Amazon Lightsail | Simplified cloud platform offering VPS, containers, and databases with predictable pricing. |
| AWS Outposts | Extends AWS infrastructure and services to on-premises locations for low-latency, local data processing. |
| AWS CloudFormation | Infrastructure as code service for provisioning and managing AWS resources using templates. |
| Amazon Virtual Private Cloud (VPC) | Provisions a logically isolated section of the AWS Cloud to launch resources in a virtual network you define. |
| Subnet | A section of a VPC used to organize resources; can be public or private. |
| Internet Gateway | A connection between a VPC and the internet that allows public traffic to access the VPC. |
| Virtual Private Gateway | Allows protected traffic to enter the VPC from an approved private network. |
| AWS Client VPN | Fully managed, elastic VPN service connecting remote workers and on-premises networks to the cloud. |
| AWS Site-to-Site VPN | Creates a secure connection between a data center or branch offices and AWS Cloud resources. |
| AWS PrivateLink | Privately connects a VPC to services and resources as though they were in your VPC. |
| AWS Direct Connect | Provides a dedicated private connection between your data center and a VPC. |
| Network ACL | Allows or denies specific inbound or outbound traffic at the subnet level using stateless packet filtering. |
| Security Groups | Control inbound and outbound traffic for a resource at the instance level using stateful packet filtering. |
| Domain Name System (DNS) | Translates human-readable domain names to machine-readable IP addresses. |
| Amazon Route 53 | Scalable, reliable DNS web service that routes users to applications; supports domain registration, health checks, and traffic routing. |
| Amazon CloudFront | CDN service that speeds up delivery of web content to users through a global network of edge locations. |
| AWS Global Accelerator | Improves availability and performance of applications for global users by routing traffic through the AWS global network. |
| Amazon Transit Gateway | A network transit hub used to interconnect VPCs and on-premises networks. |
| NAT Gateway | Allows instances in a private subnet to connect to services outside the VPC, without allowing external services to initiate a connection. |
| Amazon API Gateway | Service for creating, publishing, maintaining, monitoring, and securing APIs at any scale. |
| Amazon EC2 Instance Store | Temporary, non-persistent, high-performance storage directly attached to the host of an EC2 instance. |
| Amazon Elastic Block Store (EBS) | Scalable block storage service providing persistent, high-performance volumes attached to EC2 instances. |
| Amazon EBS Snapshots | Point-in-time backups of EBS volumes, used to protect and restore data. |
| Amazon Data Lifecycle Manager | Automates the creation, retention, and deletion of Amazon EBS snapshots. |
| Amazon Simple Storage Service (S3) | Scalable object storage service for storing and retrieving any amount of data from anywhere. |
| Amazon S3 Storage Classes | A range of storage tiers, from high-performance frequent access to cost-effective archival, for different retrieval needs and budgets. |
| Amazon S3 Versioning | Keeps multiple variants of objects, enabling recovery from unintended deletions or modifications. |
| Amazon S3 Buckets | Cloud storage containers that securely hold data, with access and management through AWS. |
| Amazon Elastic File System (EFS) | Scalable, fully managed file storage that lets multiple AWS resources access shared data simultaneously. |
| Amazon FSx | Fully managed file storage service supporting file systems like Windows File Server, Lustre, NetApp ONTAP, and OpenZFS. |
| Amazon FSx for Windows File Server | Reliable, high-performance file storage compatible with Windows applications. |
| Amazon FSx for NetApp ONTAP | File storage with advanced data management capabilities, compatible with Windows and Linux workloads. |
| Amazon FSx for OpenZFS | High-performance, scalable storage using the open-source ZFS file system. |
| Amazon FSx for Lustre | Accelerates compute-intensive workloads by providing fast data access. |
| AWS Storage Gateway | Hybrid cloud storage service providing seamless, secure integration between on-premises environments and AWS storage. |
| Amazon S3 File Gateway | A Storage Gateway configuration providing local file access to S3 objects while caching frequently accessed data locally. |
| Tape Gateway | A Storage Gateway configuration for backing up data to S3 while maintaining compatibility with tape-based backup applications. |
| Volume Gateway | A Storage Gateway configuration providing iSCSI block storage volumes to on-premises applications, in cached or stored modes. |
| Amazon Relational Database Service (RDS) | Relational database service supporting engines like MySQL, PostgreSQL, and Microsoft SQL Server, with automated maintenance and backups. |
| Amazon RDS Security | Security configurations and controls available for protecting Amazon RDS databases. |
| Amazon Aurora | Cloud-native relational database offering superior performance and availability, with MySQL and PostgreSQL compatibility. |
| AWS Database Migration Service (DMS) | Provides seamless database migration between source and target databases while keeping the source operational. |
| Amazon DynamoDB | NoSQL database service providing single-digit millisecond performance at any scale, with built-in security. |
| Amazon ElastiCache | In-memory caching service supporting Redis, Valkey, or Memcached to improve application performance. |
| Amazon DocumentDB | MongoDB-compatible document database service designed for mission-critical workloads with automatic scaling. |
| AWS Backup | Centralized service for automating and managing data backups across AWS services and on-premises resources. |
| Amazon Neptune | Graph database service optimized for storing and querying highly connected data relationships. |
| Amazon Comprehend | Uses natural language processing to extract key insights from documents. |
| Amazon Polly | Converts text into lifelike speech. |
| Amazon Transcribe | Converts speech into text. |
| Amazon Translate | Translates text into multiple languages. |
| Amazon Kendra | Uses natural language processing to intelligently search enterprise content. |
| Amazon Rekognition | Identifies objects, people, text, scenes, and activities in images and videos. |
| Amazon Textract | Detects and extracts typed and handwritten text from documents. |
| Amazon Lex | Adds voice and text conversational interfaces to applications. |
| Amazon Personalize | Adds personalized customer recommendations to applications based on historical data. |
| Amazon SageMaker AI | Build, train, and deploy your own ML models without managing infrastructure. |
| Amazon SageMaker JumpStart | Deploy pre-trained ML solutions, like computer vision, NLP, and tabular data, with just a few clicks. |
| Amazon Bedrock | Fine-tune and integrate large foundation models from Amazon and leading AI startups into applications via a single API. |
| Amazon Q Business | Answers questions and solves problems using data and expertise from a company's information repositories. |
| Amazon Q Developer | Accelerates development with AI-generated code recommendations. |
| Amazon Kinesis Data Streams | Ingests terabytes of streaming data in real time from applications, streams, and sensors. |
| Amazon Data Firehose | Ingests and delivers data within seconds to destinations such as data lakes and warehouses. |
| Amazon Redshift | Fully managed data warehouse for storing and analyzing petabytes of structured or semistructured data using complex SQL queries. |
| AWS Glue Data Catalog | Centralized repository that provides metadata to various analytics services. |
| AWS Glue | Processes and prepares data for analytics, using the AWS Glue Data Catalog as a reference. |
| Amazon EMR | Processes big data workloads using popular frameworks like Apache Spark. |
| Amazon Athena | Analyzes data from various sources hosted anywhere using a single SQL query. |
| Amazon QuickSight | Visualizes data by creating interactive dashboards, with or without technical expertise. |
| Amazon OpenSearch Service | Visualizes and monitors real-time data analytics with keyword or natural language searches. |
| AWS Identity and Access Management (IAM) | Securely manages identities and access to AWS services and resources. |
| AWS IAM Identity Center | Connects an existing workforce identity source and centrally manages single sign-on access to AWS. |
| AWS Secrets Manager | Centrally stores and manages credentials, API keys, and other secrets. |
| AWS Systems Manager | Manages nodes, or connection points, at scale across AWS and multi-cloud/hybrid environments. |
| AWS Shield | Protects networks and applications from common, frequently occurring types of DDoS attacks. |
| AWS WAF | Protects applications by blocking traffic from IP addresses defined in a web ACL. |
| AWS Key Management Service (KMS) | Creates and manages cryptographic keys used to encrypt and decrypt data. |
| Amazon Macie | Uses machine learning to discover and protect sensitive data stored in Amazon S3. |
| AWS Certificate Manager (ACM) | Creates and manages SSL/TLS certificates that provide data encryption in transit. |
| Amazon Inspector | Checks applications for security vulnerabilities and deviations from security best practices. |
| Amazon GuardDuty | Continuously monitors the AWS environment using intelligent threat detection. |
| Amazon Detective | Analyzes detected threats with interactive visualizations in a unified view. |
| AWS Security Hub | Aggregates security findings from AWS and partner services and organizes them into actionable insights. |
| Amazon CloudWatch | Monitors AWS resources and applications in real time, providing visibility into utilization, performance, and health. |
| AWS CloudTrail | Records user activity and API calls as events, helping answer "who did what, where, and when." |
| AWS Artifact | Self-service portal providing on-demand access to AWS security and compliance documentation, reports, and agreements. |
| AWS Config | Assesses, audits, and evaluates the configurations of AWS resources. |
| AWS Audit Manager | Continually audits AWS usage to streamline risk and compliance assessment. |
| AWS Organizations | Centrally manages and governs an environment as it grows, managing policies for groups of accounts and automating account creation. |
| AWS Control Tower | Enforces and manages governance rules for security, operations, and compliance at scale across accounts. |
| AWS Service Catalog | Lets you create, share, and organize a curated catalog of AWS resources for consistent governance across accounts. |
| AWS License Manager | Helps manage software licenses and fine-tune licensing costs. |
| AWS Trusted Advisor | Optimizes costs, performance, security, and resilience through continuous best-practice checks. |
| AWS Health | Data source for events and changes affecting AWS resources; notifies about service events, planned changes, and account notifications. |
| AWS IAM Access Analyzer | Helps set, verify, and refine security permissions to achieve least-privilege access. |
