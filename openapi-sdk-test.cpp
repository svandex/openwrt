#define ALIBABACLOUD_SHARED

#include <iostream>
#include <alibabacloud/core/AlibabaCloud.h>
#include <alibabacloud/alidns/AlidnsClient.h>
#include <alibabacloud/core/Credentials.h>

using namespace AlibabaCloud;
using namespace AlibabaCloud::Alidns;

int main() {
	try{
		//Initialize the SDK
		AlibabaCloud::InitializeSdk();

		//Configure the ECS instance
		ClientConfiguration configuration("cn-hangzhou");
		// specify timeout when create client.
		configuration.setConnectTimeout(1500);
		configuration.setReadTimeout(4000);

		//Configure Credentials
		std::string accessKeyId("");
		std::string accessKeySecret("");
		Credentials credential(accessKeyId,accessKeySecret);

		AlidnsClient client(credential,configuration);

		// Create an API request and set parameters
		//Model::DescribeDomainsRequest request;
		
		Model::DescribeDomainRecordsRequest request;
		request.setDomainName("svandex.cn");
		//request.setPageSize(10);
		// specify timeout when request
		request.setConnectTimeout(1000);
		request.setReadTimeout(6000);


		auto outcome =client.describeDomainRecords(request);

		if (!outcome.isSuccess()) {
			// Handle exceptions
			std::cout << outcome.error().errorCode() << std::endl;
			AlibabaCloud::ShutdownSdk();
			return -1;
		}

		//std::cout << "version name: " << outcome.result().getVersionName() << std::endl;
		for(auto domain : outcome.result().getDomainRecords()){
			std::cout<<"Domain Name: \t"<<domain.domainName<<std::endl;
			std::cout<<"Domain Value: \t"<<domain.value<<std::endl;
			std::cout<<"RR: \t"<<domain.rR<<std::endl;
		}

	}catch(std::exception &e){
		std::cout<<e.what()<<std::endl;
	}

	// Close the SDK
	AlibabaCloud::ShutdownSdk();
	return 0;
}

