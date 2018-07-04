#pragma once
#include "Object.h"
#include "Struct.generated.h"
/**
*
*/
USTRUCT(BlueprintType)
struct FMyEnemy {

	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "MyEnemyStruct")
		int32 Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnemyStruct")
		int32 EnemyCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnemyStruct")
		float TimeSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnemyStruct")
		bool Spawned;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyEnemyStruct")
		FString EnemyActorName;


};