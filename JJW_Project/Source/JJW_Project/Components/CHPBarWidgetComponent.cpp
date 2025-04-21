#include "Components/CHPBarWidgetComponent.h"
#include "UI/CUI_EnemyHPBar.h"
#include "Enemy/CEnemyBase.h"

UCHPBarWidgetComponent::UCHPBarWidgetComponent()
{
	ConstructorHelpers::FClassFinder<UCUI_EnemyHPBar> HPBarWidget(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/Blueprints/UI/WBP_CUI_EnemyHPBar.WBP_CUI_EnemyHPBar_C'"));

	if (HPBarWidget.Succeeded())
	{
		SetWidgetClass(HPBarWidget.Class);
	}

	SetWidgetSpace(EWidgetSpace::Screen);
	SetDrawSize(FVector2D(200.f, 50.f));
}

void UCHPBarWidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* HPbarwidget = GetUserWidgetObject();
	if (!HPbarwidget) return;

	UCUI_EnemyHPBar* HPbarInstance= Cast<UCUI_EnemyHPBar>(HPbarwidget);
	if (!HPbarInstance) return;

	ACEnemyBase* enemyOwner = Cast<ACEnemyBase>(GetOwner());
	if (!enemyOwner) return;

	enemyOwner->OnEnemyHealthUIUpdate.AddDynamic(HPbarInstance, &UCUI_EnemyHPBar::OnEnemyHealthUIUpdate);
}
