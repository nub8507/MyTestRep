#pragma once
#include "EngineMinimal.h"
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


USTRUCT(BlueprintType)
struct FMyGameZonePart {

	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyGameZone")
		FVector Min;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyGameZone")
		FVector Max;
};

USTRUCT(BlueprintType)
struct FMyGameZone {

	GENERATED_USTRUCT_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyGameZone")
		TArray<FMyGameZonePart> Zones;
};
